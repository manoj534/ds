#include <stdio.h>
#include <stdlib.h>

int push();
int pop();
int traverse();
int peek();

struct node{
	int data;
	struct node *link;
};

struct node *top = NULL;

int main()
{
	int element;
	while (1) {
		printf("enter 1 for push\n");
		printf("enter 2 for pop\n");
		printf("enter 3 for travers\n");
		printf("enter 4 for peek element\n");
		printf("enter 5 for exit\n");
		scanf("%d",&element);
		switch ( element ) {
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				traverse();
				break;
			case 4:
				peek();
				break;
			case 5:
				exit(1);
			default :
				printf("enter a valid\n");
		}
	}
}

int push()
{
	struct node *temp;
	temp = (struct node*) malloc(sizeof(struct node));
	printf("enter the data\n");
	scanf("%d",&temp->data);
	temp -> link = top;
	top = temp;
	
}

int pop()
{
	struct node *p;
	printf("%d",top->data);
	p = top -> link;
	top -> link = NULL;
	top = p;
}

int traverse()
{
	struct node *temp;
	temp = top;
	if ( temp != NULL ) {
		while ( temp != NULL ) {
			printf("%d\t",temp -> data);
			temp = temp -> link;
		}
	} else {
		printf("stack is empty\n");
	}
}

int peek()
{
	if ( top != NULL ) {
		printf("%d",top-> data);
	} else {
		printf("stack is empty\n");
	}
}

