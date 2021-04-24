#include <stdio.h>
#include <stdlib.h>

int push();
int pop();
int peek();
int display();

struct node{
	int data;
	struct node *link;
};
struct node *top;

int main()
{
	int element;
	while (1) {
		printf("enter 1 for push\n");
		printf("enter 2 for pop\n");	
		printf("enter 3 for peek\n");
		printf("enter 4 for display\n");
		scanf("%d",&element);
		switch ( element ) {
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				peek();
				break;
			case 4:
				display();
				break;
			case 5:
				exit(1);
			default :
				printf("invalid value\n");
		}
	}
}

int push()
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("enter the data\n");
	scanf("%d",&temp->data);
	temp -> link = NULL;
	if ( top == NULL ) {
		top = temp;
	} else {
		struct node *add;
		add = top;
		temp -> link = top;
		top = temp;
	}
}

int pop()
{
	if ( top == NULL ) {
		printf("stack is empty\n");
	} else {
		printf("%d\n",top->data);
		top = top -> link;
	}
}

int peek()
{
	if ( top == NULL ) {
		printf("stack is empty\n");
	} else {
		printf("%d\n",top -> data);
	}
}

int display()
{
	struct node *temp;
	temp = top;
	if ( top == NULL ) {
		printf(" stack is empty\n");
	} else {
		while( temp != NULL ) {
			printf("%d\t",temp-> data);
			temp = temp -> link;
		}
	}
}
