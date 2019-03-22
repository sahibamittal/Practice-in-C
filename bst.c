#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// Binary Search Tree
// author - Sahiba Mittal

typedef struct node{

	int val;
	struct node *left, *parent, *right;
} node;

void initiate_node(node ** new_node, int val);
void insert(node ** root, int val);
void printDFS(node * root);
struct node * search(node * root, int val);
void remove_node(node ** root, int val);
struct node * find_min(node * root);
struct node * find_max(node * root);
struct node * search_next_highest(node * root, int val);
bool isBST(node * root, int min, int max);

int main(){

	// creating root node
	node * root = malloc(sizeof(node));
	root = NULL;

	insert(&root, 7);
	insert(&root, 3);
	insert(&root, 5);
	insert(&root, 8);
	printDFS(root);
	search(root, 6);
	node * next_highest = search_next_highest(root, 8);
	if(next_highest != NULL)
		printf("\nNext highest value after 8 is %d\n", next_highest->val);
	
	//remove_node(&root, 5);
	//printDFS(root);
	
	int min = (find_min(root))->val;
	int max = (find_max(root))->val;
	bool validate = isBST(root, min, max);
	printf("\nIs it a BST? %s", validate?"true":"false");

	return(0);
}

bool isBST(node * root, int min, int max){

	if(root == NULL)
		return true;
	if(root->val < min || root->val > max)
		return false;

	return isBST(root->left, min, root->val) && isBST(root->right, root->val, max);
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
		(*root)->parent = NULL;
		return;
	}

	// value to be inserted is smaller than value in current root
	if(n < current->val){
	
		if(current->left != NULL)
			insert(&(current->left), n);

		else{
			initiate_node(&(current->left), n);
			current->left->parent = current;
		}
	}

	// value to be inserted is greater equal than value in current root
	else{
	
		if(current->right != NULL)
			insert(&(current->right), n);
		else{
			initiate_node(&(current->right), n);
			current->right->parent = current;
		}
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

struct node * search(node * root, int val){

	// tree is empty OR leaf node is reached
	if(root == NULL){

		printf("\n%d NOT FOUND!", val);
		return NULL;	
	}

	if(val < root->val)
		return search(root->left, val);
		
	if(root->val == val){

		printf("\n%d FOUND!", val);
		return root;
	}

	if(val > root->val)
		return search(root->right, val);
}

struct node * find_min(node * root){

	while(root->left != NULL)
		root = root->left;

	return root;
}

struct node * find_max(node * root){

	while(root->right != NULL)
		root = root->right;

	return root;
}

struct node * search_next_highest(node * root, int val){

	node * current = search(root, val);

	// find minimum child value in right sub-tree 
	if(current->right != NULL){
		
		node * min = find_min(current->right);
		return min;
	}	

	// no right sub-tree = no successor with higher value = look for parent
	while(current->parent != NULL){

		if(current->parent->left == current)
			return current->parent;

		current = current->parent;
        }

	// no higher value available
	printf("\nNo higher value than %d exists",val);
	return NULL;
}

void remove_node(node ** root, int val){

	node * to_remove = search(*root, val);

	// node to be removed is not in the list
	if(to_remove == NULL)
		return;

	// node to be removed is a leaf node
	if(to_remove->left == NULL && to_remove->right == NULL){
	       	
		if(to_remove->parent->left == to_remove)
			to_remove->parent->left = NULL;
		if(to_remove->parent->right == to_remove)
			to_remove->parent->right = NULL;
		free(to_remove);
	}

	// node to be removed has no right sub-tree
	else if(to_remove->right == NULL){
		
		to_remove->left->parent = to_remove->parent;
		if(to_remove->parent != NULL)
			to_remove->parent->left = to_remove;
		free(to_remove);
	}	

	// node to be removed has right subtree
	else{

		// find next highest node to replace it
		node * temp = search_next_highest(to_remove, val);
		to_remove->val = temp->val;

		if(temp->parent->left == temp)
			temp->parent->left = NULL;
		else
			temp->parent->right = NULL;
		free(temp);		
	}
	
	printf("\nRemoved");
	return;
}
