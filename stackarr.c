#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int push(int );
int pop();
int peek();
int traverse();
int isfull();
int isempty();

int stack[SIZE];
int top = -1;

int main()
{
	int element;
	int var;
	int init = 0;
	while(1) {
		printf("enter 1 for push\n");
		printf("enter 2 for pop\n");
		printf("enter 3 for peek\n");
		printf("enter 4 for traverse\n");
		printf("enter 5 for exit\n");
		scanf("%d",&element);
	
		switch (element) {
			case 1 : 
			     printf("\nenter element to push into stack\t");
			     scanf("%d",&var);
			     push(var);
		             break;
			case 2:
			     init = pop();
		             if ( init == 0 ) {
				printf("stack is empty\n");
			     } else {
				printf("%d is deleted\n",init);
			     }
			     break;
			case 3 :
		       	     init = peek();
			     if ( init == 0 ) {
				printf("stack is empty\n");	
			     } else {
				printf("%d is peek element\n",init);
			     }
			     break;
			case 4 :
			     traverse();
			     break;
			case 5:
			     exit(1);
			default :
			     printf("entered number is invalid\n" );
		}
	}
}
		
int push(int var)
{
	if ( isfull() == 0) {
		printf("stack is full\n");
	} else {
		stack[++top] = var;
	}
}
int pop()
{
	if ( isempty() == 0 ) {
		return 0;
	} else {
		return stack[top--];
	}
}

int peek()
{
	if ( isempty() == 0) {
		return 0;
	} else {
		return stack[top];
	}
}
int traverse()
{
	if ( isempty() == 0) {

		printf("stcak is empty\n");

	} else {

		int i;
		for ( i = 0; i <= top; i++ ) {

			printf("%d\t",stack[i]);

		}

		printf("\n");
	}
}

int isempty()
{
	if ( top == -1 ) {
		return 0;
	} else {
		return 1;
	}
}

int isfull() {
	if ( top == (SIZE - 1) ) {
		return 0;
	} else {
		return 1;
	}
} 	
