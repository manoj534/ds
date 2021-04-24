#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

void enqueue();
void dequeue();
void display();

int arr[SIZE];
int front = -1;
int rear = -1;
int main()
{
	int n;
	while ( 1 ) {
		printf("enter number 1 to  insert\n");
		printf("enter number 2 for delete\n");
		printf("enter number 3 to display\n");
		scanf("%d",&n);
		switch ( n ) {
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(1);
			default:
				printf("invalid option\n");
		}
	}
}

void enqueue()
{
	int element;
	printf("enter element\n");
	scanf("%d",&element);
	if (((front - 1) == rear) || ((rear == (SIZE - 1) )&& (front == 0)) ) {
		printf("queue is full\n");
	} else if ( (front == - 1) && ( rear == -1 ) ) {
			front = rear = 0;
			arr[rear] = element;
	} else if ( (rear == ( SIZE - 1) && ( front != 0) )  ) {
		rear = 0;
		arr[rear] = element;
		
	} else {
		rear++;
		arr[rear] = element;
	}
}

void dequeue()
{
	int element;
	if ( (front == - 1)&& (rear == -1) ) {
		printf("queue is empty\n");
	} else if ( (front == SIZE - 1 ) ) {
		element = arr[front];
		printf("deleted element is%d\n",element);
		front = 0;
	} else if ( front == rear ) {
			front = rear = -1;
	} else {	
		element = arr[front];
		printf("deleted element is%d\n",element);
		front++;
		
	}
}

void display()
{
	int i =0;
	printf("%d %d",front,rear);
	if ( (front == 0) && (rear == SIZE - 1)) {
		for ( i = 0; i < SIZE; i++ ) {
			printf("%d\t",arr[i]);
		}
	} else {
		printf("elese statement\n");
		for ( i = front; i < SIZE; i++ ) {
			printf("%d\t",arr[i]);
		}
		if ( rear == (SIZE - 1 )) {
		}else {			
			for ( i = 0;i <= rear; i++ ) {
				printf("%d\t",arr[i]);
			}
		}
	}
}

	















