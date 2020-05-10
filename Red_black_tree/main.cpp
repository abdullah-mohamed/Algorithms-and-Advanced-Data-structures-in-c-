#include <iostream>
using namespace std;

enum Color {RED, BLACK}; 

// RBT node
struct Node{
	int data;
	struct Node *left, *right, *parent;
	bool color;
	
	Node(int val){
		this->data = val;
		left = right = parent = NULL;
		this->color = RED;
	}
};

void printNode(struct Node *tmp){
	cout << "data: " << tmp->data << " , color: " << tmp->color << "\n"; 
}

struct Node *rightRotate(struct Node *g){
	struct Node *p = g->left;
	struct Node *t = p->right;
	
	p->right = g;
	g->left = t;
	
	return p;
}

struct Node *leftRotate(struct Node *p){
	struct Node *g = p->right;
	struct Node *t = g->left;
	
	g->left = p;
	p->right = t;
	
	return g;
}


/*auto tmp = insert(n->left, val, ++curLevel);		// We need a flag to specify whether or not the returned node is going to be a child of this node
		printNode(n); cout << "\n";						// Don't change a parent through a child !! modify every node in its stack
		printNode(n->left); cout << "\n";
		cout << n->left->right ;
		n->left->parent = n;*/
struct Node *insert(struct Node *n, int val, int curLevel){		// curLevel holds the current level of RBT
	// standard BST insert
	if(n == NULL){
		struct Node *tmp = new Node(val);
		if(curLevel == 0) tmp->color = BLACK;		// It's a root node
		return tmp;
	}
	if(val > n->data){
		n->right = insert(n->right, val, ++curLevel);
		n->right->parent = n;
	}else if(val < n->data){
		n->left = insert(n->left, val, ++curLevel);
		n->left->parent = n;
	}else return n;
	
	// check if the last called child was red
	bool lastChildRed = false;
	if(val > n->data) lastChildRed = (n->right->color == RED); 
	else lastChildRed = (n->left->color == RED); 
	
	// RBT balance
	if(n->color == RED && lastChildRed){	// and the last child is red
		struct Node *uncle;
		if(n->parent->left == n) uncle = n->parent->right;		// current child is left
		else uncle = n->parent->left; 							// current child is right
		
		bool uncleColor = RED;
		if((uncle == NULL) || (uncle != NULL && uncle->color == BLACK)) uncleColor = BLACK;

		// uncle is red
		if(uncleColor == RED){
			n->color = uncle->color = BLACK;
			if(curLevel > 2) n->parent->color = RED;
		}else{
			if(n->parent->left == n){  // parent is left -- left left or left right
				if(val < n->data){		// LL
					n->color = BLACK;
					n->parent->color = RED;
					return rightRotate(n->parent);
				}else{					// LR
					struct Node *tmp = leftRotate(n);
					tmp->color = BLACK;
					tmp->parent->color = RED;
					return rightRotate(tmp);
				}
			}else{					// parent is right -- RR or RL
				if(val > n->data){		// RR
					n->color = BLACK;
					n->parent->color = RED;
					return leftRotate(n->parent);
				}else{					// RL
					struct Node *tmp = rightRotate(n);
					tmp->color = BLACK;
					tmp->parent->color = RED;
					return leftRotate(tmp);
				}
			}
		}
	}
	return n;
}

void printInorder(struct Node *root){
	printNode(root);
	if(root->left != NULL) printInorder(root->left);
	// cout << root->data << " ";
	if(root->right != NULL) printInorder(root->right);
}

int main(){
	struct Node *root = NULL;
	root = insert(root, 12, 0);
	insert(root, 5, 0);
		cout << "+++++++++++++\n";
	insert(root, 3, 0);
	/*insert(root, 10, 0);
	insert(root, 4, 0); 
	insert(root, 8, 0);
	insert(root, 11, 0);*/
	// insert(root, 14, 0);
	/*insert(root, 6, 0);
	insert(root, 17, 0);
	insert(root, 13, 0);
    insert(root, 14, 0);
	insert(root, 15, 0);
	insert(root, 7, 0);*/
    
	// print inoder traversal of the BST 
    /*printInorder(root); 
	cout << "\n";*/
	return 0;
}