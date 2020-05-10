#include <stdio.h>
#include <stdlib.h>
#include "RBT.h"

static void insert_repair(rbtree *rbt, rbnode *current);
static void delete_repair(rbtree *rbt, rbnode *current);
static void rotate_left(rbtree *, rbnode *);
static void rotate_right(rbtree *, rbnode *);
static int check_order(rbtree *rbt, rbnode *n, void *min, void *max);
static int check_black_height(rbtree *rbt, rbnode *node);
static void print(rbtree *rbt, rbnode *node, void (*print_func)(void *), int depth, char *label);
static void destroy(rbtree *rbt, rbnode *node);
/*
 * construction
 * return NULL if out of memory
 */
rbtree *rb_create(int (*compare)(const void *, const void *), void (*destroy)(void *))
{
	rbtree *rbt = new(std::nothrow) rbtree();
	if(!rbt) return NULL;
	
	rbt->compare = compare;
	rbt->destroy = destroy;
	
	rbt->nil.left = rbt->nil.right = rbt->nil.parent = RB_NIL(rbt);
	rbt->nil.color = BLACK;
	rbt->nil.data = NULL;
	
	rbt->root.left = rbt->root.right = rbt->root.parent = RB_NIL(rbt);
	rbt->root.color = BLACK;
	rbt->root.data = NULL;
	
	#ifdef RB_MIN
	rbt->min = NULL; 
	#endif
	return rbt;
}

/*
 *  destruction 
 */
void rb_destroy(rbtree *rbt)
{
	destroy(rbt, RB_FIRST(rbt));
	free(rbt);
}

/*
 * look up
 * return NULL if not found
 */
rbnode *rb_find(rbtree *rbt, void *data)
{
	rbnode *p;
	
	p = RB_FIRST(rbt);
	
	while(p != RB_NIL(rbt))
	{
		int cmp = rbt->compare(data, p->data);
		if(cmp == 0) return p;
		p = cmp < 0 ? p->left : p->right;
	}
	if(p->data == *data) return p;
	
	return NULL;
}

/*
 * next larger
 * return NULL if not found
*/
rbnode *rb_successor(rbtree *rbt, rbnode* node)
{
	rbnode *p;
	
	p = node->right;
	
	if(p != RB_NIL(rbt))
	{
		/* move down till you find it */
		for( ; p->left != RB_NIL(rbt); p = p->left);
	}
	else
	{
		/* move up till you find it or hit root */
		for(p = node->parent; node == p->right; node = p, p = p->parent);
		
		if(p == RB_ROOT(rbt)) p = NULL;
	}
	
	return p;
}

/*
 * apply fn
 * return non-zero if error
 */
int rb_apply(rbtree *rbt, rbnode *node, int (*func)(void *, void *), void *cookie, enum rbtraversal order)
{
	// ?
}

/*
 * rotate left about x
 */
void rotate_left(rbtree *rbt, rbnode *x){
	rbnode *y = x->right;
	
	// tree x
	x->right = y->left;
	if(t != RB_NIL(rbt)) x->right->parent = x;
	
	// tree y
	y->parent = x->parent;
	if(x == x->parent->left) x->parent->left = y;
	else x->parent->right = y;
	
	y->left = x;
	x->parent = y; 
}

/*
 * rotate right about x
 */
void rotate_left(rbtree *rbt, rbnode *x){
	rbnode *y = x->left;
	
	// tree x
	x->left = y->right;
	if(t != RB_NIL(rbt)) x->left->parent = x;
	
	// tree y
	y->parent = x->parent;
	if(x == x->parent->left) x->parent->left = y;
	else x->parent->right = y;
	
	y->right = x;
	x->parent = y; 
}

/*
 * insert (or update) data
 * returns NULL if out of memory
 */
rbnode *rb_insert(rbtree *rbt, void *data)
{
	rbnode *p = RB_ROOT(rbt);
	
	// get position
	while(p != RB_NIL(rbt))
	{
		if(p->data > data) p = p->left;
		else if (p->data < data) p = p->right;
		else // we might need this to update a node
	}
	
	rbnode *tmp = p;
	p = new(std::nothrow) rbnode();
	if(!p) return NULL;					// allocation failed
	
	p->data = data;
	p->left = p->right = RB_NIL(rbt);
	p->color = RED;
	p->parent = tmp->parent;
	if(p == RB_ROOT(rbt)) p->color = BLACK;
	
	// adjust colors if needed
	while(p != RB_ROOT(rbt))
	{
		if(p->parent->color == RED && p != RB_ROOT(rbt))
		{
			// get color of uncle
			rbnode *uncle;
			if(p == p->parent->left) uncle = p->parent->right;
			else uncle = p->parent->left;
			
			if(uncle->color == RED)
			{
				p->parent->color = uncle->color = BLACK;
				p->parent->parent->color = RED;
				p = p->parent->parent;
				if(p == RB_ROOT(rbt)) p->color = BLACK;
			}
			else
			{
				if(p->parent == p->parent->parent->left)	// parent is left child
				{
					if(p == p->parent->left)		// left left case
					{
						rightRotate(rbt, p->parent->parent);
						char tmp = p->parent->parent->color;
						p->parent->parent->color = p->parent->color;
						p->parent->color = tmp;
					}
					else							// left right case
					{
						leftRotate(rbt, p);
						rightRotate(rbt, p->parent->parent);
						char tmp = p->parent->parent->color;
						p->parent->parent->color = p->parent->color;
						p->parent->color = tmp;
					}
				}
				else						// parent is right child
				{
					if(p == p->parent->right)		// right right case
					{
						leftRotate(rbt, p->parent->parent);
						char tmp = p->parent->parent->color;
						p->parent->parent->color = p->parent->color;
						p->parent->color = tmp;
					}
					else							// right left case
					{
						rightRotate(p);
						leftRotate(rbt, p->parent->parent);
						char tmp = p->parent->parent->color;
						p->parent->parent->color = p->parent->color;
						p->parent->color = tmp;
					}
					}
				}
			}
		}
	}
	return p;
}