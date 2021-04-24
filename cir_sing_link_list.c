#include <stdio.h>
#include <stdlib.h>

int display();
int insert_end();

struct node{
	int data;
	struct node *link;
};

struct node *root = NULL;

int main()
{
	int element;
	while (1) {
		printf("enter 1 to  display\n");
		printf("enter 2 to insert at the end");
		scanf("%d\n",&element);
		switch (element) {
			case 1:
				display();
				break;
			case 2:
				insert_end();
				break;
			case 3:
				exit(1);
			default :
				printf("invalid value\n");
		}
	}
}

int insert_end()
{
	struct node *temp = NULL;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("enter data");
	scanf("%d",&temp->data);
	temp -> link = NULL;
	if ( root == NULL ) {
		temp -> link = temp;
		root = temp;
	} else {
		temp -> link = root -> link;
		root -> link = temp;
		root = temp;
	}
}

int display()
{
	struct node *temp = NULL;
	temp = root -> link;
	if ( root == NULL ) {
		printf("list is empty\n");
	} else {
		while ( temp -> link != root -> link ){ 
			printf("%d",temp -> data);
			temp = temp -> link;
		}
	}
}
	
