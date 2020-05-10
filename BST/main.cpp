#include <iostream>
#include <cstdlib>

using namespace std;

struct node 
{ 
    int key; 
    struct node *left, *right;
	
	/* Node(int data) 
    { 
        this->key = data; 
        left = right = NULL; 
    } */
};


struct node* insert(struct node* root, int val){
	if(root == NULL) {
		root = new node();
		root->key = val;
		root->right = root->left = NULL;
		return root;
	}
	
	if(val > root->key)	root->right = insert(root->right, val);
	else if(val < root->key) root->left = insert(root->left, val);
	return root;
}

void printInorder(struct node *root){
	if(root->left != NULL) printInorder(root->left);
	cout << root->key << " ";
	if(root->right != NULL) printInorder(root->right);
}

struct node* search(struct node* root, int val){
	if(root->key == val) return root;
	else if(root->key > val && root->left != NULL) return search(root->left, val);
	else if(root->key < val && root->right != NULL) return search(root->right, val);
	return NULL;
}

struct node* minValueNode(struct node* node){
	if(n == NULL || n->left == NULL) return n;
	minValueNode(n->left);
	/*if(node != NULL) {
		if(node->left->left == NULL) return node->left;
		if(node->left != NULL) minValueNode(node->left);
		else return NULL;
	}else return node;*/
}


struct node* deleteNode(struct node* root, int val){
	if(root == NULL) return root;
	
	if(root->key > val)	root->left = deleteNode(root->left, val);
	else if(root->key < val) root->right = deleteNode(root->right, val);
	else{
		if(root->right == NULL){
			struct node* tmp = root->left;
			free(root);
			return tmp;
		}else if(root->left == NULL){
			struct node* tmp = root->right;
			free(root);
			return tmp;
		}
		
		struct node* temp = minValueNode(root->right);
		root->key = temp->key;
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}

bool checkBST(struct node* n){
	if(n == NULL) return true;
	if(n->right != NULL) 
		if(n->right->key < n->key) return false;
		
	if(n->left != NULL) 
		if(n->left->key > n->key) return false;
	
	return checkBST(n->right) && checkBST(n->left);
}

int main(){
	/* Let us create following BST 
              50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80 */
    struct node *root = NULL; 
    root = insert(root, 50); 
    insert(root, 30);
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80);
	
    // print inoder traversal of the BST 
    printInorder(root); 
	cout << "\n";
	
	// search for element
	cout << (search(root, 89) == NULL) << "\n";
	cout << (search(root, 20) == NULL) << "\n";
	
	// search for the min value in a BST
	cout << minValueNode(root)->key << "\n";
	
	/*// delete a node
	deleteNode(root, 40);
	printInorder(root); 
	cout << "\n";
	
	deleteNode(root, 20);
	printInorder(root); 
	cout << "\n";*/

	// check BST
	cout << checkBST(root) << "\n";
	root->left->key = 1000;
	cout << checkBST(root) << "\n";
	
    return 0; 
} 