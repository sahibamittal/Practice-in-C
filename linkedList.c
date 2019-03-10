#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int val;
	struct node * next;
} node;

void printList(node * head);
void push_in_end(node ** head, int n);
void push_in_beg(node ** head, int n);
void push_after_value(node * head, int curr, int n);
void push_before_value(node ** head, int curr, int n);
int pop_beg(node ** head);
int pop_end(node ** head);
int pop_by_val(node ** head, int val);
int pop_by_index(node ** head, int i);

int main(){

	// creating head
	node * head;
	head = malloc(sizeof(node));
	head = NULL;
	//if(head==NULL)
	  //      return 1;
	//head->val = 1;
	//(*head).next= NULL;

	//head->next = malloc(sizeof(node));
	//head->next->val = 2;
	//head->next->next = NULL;

	push_in_end(&head, 3);
	push_in_beg(&head, 0);
	push_after_value(head, 3, 44);
	push_before_value(&head, 44, 7);
	//pop_beg(&head);
	//pop_end(&head);
	pop_by_index(&head,4);
	printList(head);	
}

void printList(node * head){

	node * current = head;
	if(current == NULL)
		printf("\nEmpty");
	while(current != NULL){
		printf("%d ", current->val);
		current = current->next;
	}
}

void push_in_end(node ** head, int n){

	// if list is empty
	if(*head == NULL){

		push_in_beg(head, n);
		return;
	}
	node * current = *head;
	while(current->next != NULL)
		current = current->next;
	current->next = malloc(sizeof(node));
	current->next->val = n;
	current->next->next = NULL;
}

void push_in_beg(node ** head, int n){

	node * new_node = malloc(sizeof(node));
	new_node->val = n;
	new_node->next = (*head);
	(*head) = new_node;
}

void push_after_value(node * head, int curr, int n){

	node * current = head;
	node * new_node = malloc(sizeof(node));
	new_node->val = n;
	while(current->val != curr){
		// check if end of list is reached
		if(current->next == NULL){

			printf("item %d not found\n",curr); 
			return;
		}
		current = current->next;
	}
	new_node->next = current->next;
	current->next = new_node;
}

void push_before_value(node ** head, int curr, int n){

	// case when curr is in first node
	if((*head)->val == curr)
		return push_in_beg(head, n);

	node * current = *head;
	node * new_node = malloc(sizeof(node));
	new_node->val = n;
	while(current->next->val != curr){
		// check if end of list id reached
		if(current->next->next == NULL){

			printf("item %d not found\n", curr);
			return;
		}
		current = current->next;
	}
	new_node->next = current->next;
	current->next = new_node;
}

int pop_beg(node ** head){

	int retval = -1;
	if(*head != NULL){

		retval = (*head)->val;
		node * temp = (*head)->next;
		free(*head);
		*head = temp;
	}
	return retval;
}

int pop_end(node ** head){

	int retval = -1;
	node * current = *head;
	// list must not be empty
	if(current != NULL){

		// if list has only one node
		if(current->next == NULL){

			retval = current->val;
			retval = pop_beg(head);
			return retval;
		}
		// else
		while(current->next->next != NULL)
			current = current->next;
		
		retval = current->next->val;
		free(current->next);
		current->next = NULL;
	}
	return retval;
}

int pop_by_val(node ** head, int val){

	int retval = -1;
	node * current = *head;

	// list is empty
	if(current == NULL)
		return -1;
	
	// value exists in first node
	if(current->val == val)
		return pop_beg(head);
	
	while(current->next->val != val){
		
		if(current->next->next == NULL){

			printf("item %d not in list\n",val);
			return -1;
		}
		current  = current->next;
	}
	node * temp = current->next;
	retval = temp->val;
	current->next = temp->next;
	free(temp);
	return retval;
}

int pop_by_index(node ** head, int i){

	int retval = -1;
	node * current = *head;

	// list is empty
	if(current == NULL)
		return -1;

	//if index = 0 = first node
	if(i == 0)
		return pop_beg(head);

	for(int a=1; a<i; a++){
	
		current = current->next;
		// last index is reached
		if(current->next == NULL){

			printf("Out of bound index\n");
			return -1;
		}
	}
	node * temp = current->next;
	retval = temp->val;
	current->next = temp->next;
	free(temp);
	return retval;
}
