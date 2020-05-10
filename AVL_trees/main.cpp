#include <iostream>
#include <cstdlib>
using namespace std;
/*
 *  AVL tree is a self balancing BST, I reimplemeneted BST.
 *  Insertion, Deletion and Check will be updated.
 */
struct node{
	int key;
	struct node *left, *right;
	int height;
};

int getHeight(node *n){
	if(n == NULL) return 0;
	return n->height;
}

int getBalance(node *n){
	if(n == NULL) return 0;
	return getHeight(n->left) - getHeight(n->right);
}

node* rightRotate(node *y){
	node* x = y->left;
	node* t = x->right;
	
	x->right = y;
	y->left = t;
	// switching the arrangement of the next 2 lines will fuck up some cases
	// be sure to update the lower node first !! 
	y->height = 1 + max(getHeight(y->left), getHeight(y->right));
	x->height = 1 + max(getHeight(x->left), getHeight(x->right));
	// cout << x->height << " " << y->height << "\n"; 
	return x;
}

node* leftRotate(node *x){
	node* y = x->right;
	node* t = y->left;
	
	y->left = x;
	x->right = t;
	
	x->height = 1 + max(getHeight(x->left), getHeight(x->right));
	y->height = 1 + max(getHeight(y->left), getHeight(y->right));
	return y;
}

struct node* insert(struct node* n, int key){
	if(n == NULL){
		struct node* tmp = new node();
		tmp->key = key;
		tmp->left = tmp->right = NULL;
		tmp->height = 1;		// leaf node
		return tmp;
	}
	
	if(n->key > key) n->left = insert(n->left, key);
	else if(n->key < key) n->right = insert(n->right, key);
	else return n;
	
	n->height = 1 + (max(getHeight(n->left), getHeight(n->right)));
	
	int balance = getBalance(n);
	
	// Left left
	if(balance > 1 && key < n->left->key)
		return rightRotate(n);
	
	// right right
	if(balance < -1 && key > n->right->key)
		return leftRotate(n);
		
	// left right
	if(balance > 1 && key > n->left->key){
		n->left = leftRotate(n->left);
		return rightRotate(n);
	}
	
	// right left
	if(balance < -1 && key < n->right->key){
		n->right = rightRotate(n->right);
		return leftRotate(n);
	}
	
	return n;
}

void printInorder(struct node* n){
	if(n == NULL) return;
	printInorder(n->left);
	cout << n->key << " ";
	printInorder(n->right);
}

struct node* search(struct node* n, int val){
	if(n == NULL) return NULL;
	if(n->key == val) return n;
	else if(n->key > val) return search(n->left, val);
	else if(n->key < val) return search(n->right, val);
}

struct node *minValueNode(struct node* n){
	if(n == NULL) return NULL;
	if(n->left == NULL) return n;
	return minValueNode(n->left);
}

struct node* deleteNode(struct node* n, int val){
	if(n == NULL) return n;
	if(n->key > val) n->left = deleteNode(n->left, val);
	else if(n->key < val) n->right = deleteNode(n->right, val);
	else if(n->key == val){
		if(n->right == NULL && n->left == NULL){
			free(n);
			return NULL;
		}
		if(n->right == NULL){
			struct node *tmp = n->left;
			free(n);
			return tmp;
		}else if(n->left == NULL){
			struct node *tmp = n->right;
			free(n);
			return tmp;
		}
		/* (Can be implemented to the right)
		 * struct node *tmp = minValueNode(n->right);
		n->key = tmp->key;
		n->right = deleteNode(tmp, tmp->key);*/
		struct node *tmp = minValueNode(n->left);
		n->key = tmp->key;
		n->left = deleteNode(n->left, tmp->key);
	}
	
	if(n == NULL) return n;
	
	// cout << n->key << ": " << getHeight(n->right) << " " << getHeight(n->left) << "\n";
	n->height = 1 + max(getHeight(n->right), getHeight(n->left));
	
	int balance = getBalance(n);
	
	// cout << n->key << "  " << n->height << "  " <<  balance << "  " << n->left->key  << "  " << getBalance(n->left) << "\n";
	// left left
	if(balance > 1 && getBalance(n->left) >= 0)
		return rightRotate(n);
	
	// left right
	if(balance > 1 && getBalance(n->left) < 0){
		n->left = leftRotate(n->left);
		return rightRotate(n);
	}
	
	// right right
	if(balance < -1 && getBalance(n->right) <= 0)
		return leftRotate(n);
	
	// right left
	if(balance < -1 && getBalance(n->right) > 0){
		n->right = rightRotate(n->right);
		return leftRotate(n);
	}
	
	return n;
}

bool checkBST(struct node *n){
	if(n == NULL) return true;
	if(n->left != NULL)
		if(n->key < n->left->key) return false;
	if(n->right != NULL)
		if(n->key > n->right->key) return false;
		
	return checkBST(n->right) && checkBST(n->left);
}

int getDepth(struct node *n){
	if(n == NULL) return 0;
	else return 1 + max(getDepth(n->right), getDepth(n->left));
}

bool checkAVL(struct node* n){
	if(n == NULL) return true;
	int t1 = getDepth(n->right)-1,				// the root always counts an extra one
		t2 = getDepth(n->left)-1;
		
	if(abs(t1-t2) > 1) return false;
	// else return true; // every change will propagate to the top but now we don't call check for children
	
	return checkAVL(n->right) && checkAVL(n->left);
}

int main(){
	struct node* root = NULL;
	root = insert(root, 40); root = insert(root, 50);
	root = insert(root, 30); root = insert(root, 10);
	root = insert(root, 32); root = insert(root, 44);
	root = insert(root, 90); root = insert(root, 1);
	// root = insert(root, -1);
	// root = insert(root, -2);
	
	printInorder(root);
	cout << "\n";
	// cout << minValueNode(root->right)->key << " \n";
	
	deleteNode(root, 32);
	printInorder(root);
	cout << "\n";
	
	cout << checkAVL(root) << "\n";
	
	/*cout << checkBST(root) << "\n"; 
	root->left->left->key = 100;
	cout << checkBST(root) << "\n";*/
	
	/*cout << getDepth(root->left->left)-1<< "\n";
	cout << getDepth(root)-1 << "\n";*/
	
	return 0;
}