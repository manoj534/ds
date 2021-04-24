#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int push(int ) ;
int pop();
int fget();
int lget();
int traverse();
int isfull();
int isempty();

int queue[SIZE];
int front = 0;
int rear = -1;

int main()
{
	int ope;
	int element;
	int i = 0;
	int init = 0;
	while (1) {
		printf("enter 1 insert an element\n");
		printf("enter 2 to delete element\n");
		printf("enter 3 to get the first element\n");
		printf("enter 4 to get the last element\n");
		printf("enter 5 to print the element\n");
		printf("enter 6 to exit\n");
	
		scanf("%d",&ope);
		switch (ope) {
			case 1:
			     printf("enter the element to push into queue\n");
			     scanf("%d",&element);
			     push(element);
			     break;
			case 2:
			     init = pop();
			     if ( init == 0 ) {
				printf("queue is empty\n");
			     } else {
				for ( i = 0; i <= rear; i++ ) {
					queue[i] = queue[i+1];
				}
				rear--;
				printf("the deleted element is %d\n",init);
			     }
	       		     break;
			case 3:
			     init = fget();
			     if ( init == 0 ) {
				 printf("queue is empty\n");
			     } else {
				 printf("%d is the first element of the queue\n",init);
			     } 
			     break;
			case 4:
			     init = lget();
			     if ( init == 0 ) {
				printf("the queue is empty\n");
			     } else {
				printf("%d is the last element of the queue\n",init);
		             }
			     break;
			case 5:
			     traverse();
			     break;
			case 6:
			     exit(1);
			default :
			     printf("enterd value is invalid please insert a valid number\n");
		}
	}
}


int push(int var) {
	if ( isfull() == 0 ) {
		printf("queue is full\n");
	} else {
		queue[++rear] = var;
	}
}

int pop()
{
	if ( isempty() == 0 ) {
		return 0;
	} else {
		return queue[front]; 
	}
}

int fget()
{
	if ( isempty() == 0 ) {
		return 0;
	} else {
		return queue[front];
	}
}
int lget()
{
	if ( isempty() == 0 ) {
		return 0;
	} else {
		return queue[rear];
	}
}

int traverse()
{
	if ( isempty() == 0 ) {
		printf("queue is empty");
	} else {
		int i ;
		for ( i = 0; i <= rear; i++ ) {
			printf("%d\t",queue[i]);
		}
	}
}

int isfull()
{
	if ( rear == (SIZE - 1 ) ) {
		return 0;
	} else {
		return 1;
	}
}

int isempty()
{
	if ( rear == front ) {
		return 0;
	} else {
		return 1;
	}
}
