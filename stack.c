// implementing stack with operations push and pop + basic operations
#include<stdio.h>
#include<stdlib.h>

typedef struct node{

	int val;
	struct node * next; 
}node;

void push(node ** top, int n);
int pop(node ** top);
void printStack(node * top);

int main(){

	node * top = NULL;
	printStack(top);
	push(&top, 2);
	printStack(top);
	push(&top, 1);
	printStack(top);
	pop(&top);
	pop(&top);
	printStack(top);
	pop(&top);
	return(0);
}

int pop(node ** top){

	int retval = -1;
	if(*top == NULL)
		printf("Nothing to pop, go home");
	else{

		node * temp = *top;
		retval = temp->val;
		*top = temp->next;
		free(temp);
	}

	return retval;
}

void push(node ** top, int n){

	node * newNode = malloc(sizeof(node));
	newNode->val = n;
	newNode->next = *top;
	*top = newNode;
}

void printStack(node * top){

	if(top == NULL)
		printf("Empty Stack");
	else {

		node * current = top;
		while(current!=NULL){

			printf("%d ",current->val);
			current = current->next;
		}
	}
	printf("\n");
}
