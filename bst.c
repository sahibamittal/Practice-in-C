#include<stdio.h>
#include<stdlib.h>

// Binary Search Tree
// author - Sahiba Mittal

typedef struct node{

	int val;
	struct node *left, *right;
} node;

void initiate_node(node ** new_node, int val);
void insert(node ** root, int val);
void printDFS(node * root);
void search(node * root, int val);
void remove_node(node ** root, int val);

int main(){

	// creating root node
	node * root = malloc(sizeof(node));
	root = NULL;

	insert(&root, 7);
	insert(&root, 3);
	insert(&root, 5);
	insert(&root, 3);
	printDFS(root);
	search(root, 6);
	search(root, 5);
	return(0);
}

void initiate_node(node ** new_node, int n){

	*new_node = malloc(sizeof(node));
	(*new_node)->val = n;
	(*new_node)->left = NULL;
	(*new_node)->right = NULL;
}

void insert(node ** root, int n){

	// use recursive calls
	// inserts data in sorted order -> BST
	
	node * current = *root;
	// empty tree
	if(current == NULL){
	
		initiate_node(root, n);
		return;
	}

	// value to be inserted is smaller than value in current root
	if(n < current->val){
	
		if(current->left != NULL)
			insert(&(current->left), n);

		else
			initiate_node(&(current->left), n);
	}

	// value to be inserted is greater equal than value in current root
	else{
	
		if(current->right != NULL)
			insert(&(current->right), n);
		else
			initiate_node(&(current->right), n);
	}
	
}

void printDFS(node * root){

	// recursive call
	// in-order traversal
	// change order of if statements below for pre/post-orders
	
	if(root == NULL)
		return;
	if(root->left != NULL)
		printDFS(root->left);
	if(root != NULL)
		printf("%d ", root->val);
	if(root->right != NULL)
		printDFS(root->right);
}

void search(node * root, int val){

	// tree is empty OR leaf node is reached
	if(root == NULL){

		printf("\n%d NOT FOUND!\n", val);
		return;	
	}

	if(val < root->val)
		search(root->left, val);
		
	if(root->val == val){

		printf("\n%d FOUND!\n", val);
		return;
	}

	if(val > root->val)
		search(root->right, val);
}
