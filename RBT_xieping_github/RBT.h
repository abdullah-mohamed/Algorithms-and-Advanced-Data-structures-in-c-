// DUPLICATION of RBT c implementation of xieping github repo
#ifndef _RB_HEADER
#define _RB_HEADER

#define RB_DUP 1
#define RB_MIN 1

#define RED 0
#define BLACK 1

enum rbtraversal {
	PREORDER,
	INORDER,
	POSTORDER
};

typedef struct rbnode {
	struct rbnode *left;
	struct rbnode *right;
	struct rbnode *parent;
	char color;						// I think this could be an enum/bool value instead of eight-8 char
	void *data;						// poly-morphic data type
} rbnode;

typedef struct{
	int (*compare)(const void *, const void *);
	void (*print)(void *);
	void (*destroy)(void *);
	
	rbnode root;
	rbnode nil;						// This makes a user-null node and it is common between all null nodes
	
	#ifdef RBMIN
	rbnode *min;
	#endif
} rbtree;

#define RB_ROOT(rbt) (&(rbt)->root);			// why use refernece not dereference operator ??  -> comes before & in precedence so this will return an address of the root root and nil are nodes not pointer to nodes
#define RB_NIL(rbt) (&(rbt)->nil);
#define RB_FIRST(rbt) ((rbt)->root.left)			// why is left is rb_first??		root doesn't contain any data, it's just a root
#define RB_MINIMAL(rbt) ((rbt)->min)

#define RB_ISEMPTY(rbt) ((rbt)->root.left == &(rbt)->nil && (rbt)->root.right == &(rbt)->nil)		// why not check root directly?
#define RB_APPLY(rbt, f, c, o) rbapply_node((rbt), (rbt)->root.left, (f), (c), (o))

rbtree *rb_create(int (*compare_fun)(const void *, const void *), void (*destroy_fun)(void *));		// for complex data types with memory allocations
void rb_destroy(rbtree *rbt);

rbnode *rb_find(rbtree *rbt, void *data);
rbnode *rb_successor(rbtree *rbt, rbnode *node);

int rb_apply_node(rbtree *rbt, rbnode *node, int (*func)(void *, void *), void *cookie, enum rbtraversal order);
void rb_print(rbtree *rbt, void (*print_func)(void *));												// why not send print with rb_create?

rbnode *rb_insert(rbtree *rbt, void *data);
void *rb_delete(rbtree *rbt, rbnode *node, int keep);

int rb_check_order(rbtree *rbt, void *min, void *max);
int rb_check_black_height(rbtree *rbt);

#endif	/* _RB_HEADER */