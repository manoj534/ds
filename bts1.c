#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *root = NULL;
void push(struct node *,struct node *);
void insert();
void display(struct node *);

int main()
{
	int elements;
	while ( 1 ) {
		printf("enter 1 for inserting into tree\n");
		printf("enter 2 for delete from tree\n");
		printf("enter 3 for display\n");
		printf("enter 4 for exit\n");
		scanf("%d",&elements);
		switch( elements ) {
			case 1:
			//	if ( root != NULL ) {
					insert();
			//	} else {
			//		printf("list is empty\n");
			//	}
				break;
			case 3:
				if ( root != NULL ) {
					display(root);
				} else {
					printf("list is empty\n");
				}
			case 4:
				exit(1);
			default :
				printf("enterd invalid value\n");
		}
	}
}

void insert()
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("enter data\n");
	scanf("%d",&temp -> data);
	temp -> left = NULL;
	temp -> right = NULL;
	if ( root == NULL ) {
		root = temp;
	} else {
		push(root,temp);
	}
}

void push(struct node *task1,struct node *temp)
{
//	struct node *temp;
	if ( task1 -> data > temp -> data  ) {
		if ( task1 -> left == NULL ) {
			task1 -> left = temp;
		} else {
			push(task1,temp);
		}
	} else {
		if ( task1 -> right == NULL ) {
			task1 -> right = temp;
		} else {
			push(task1,temp);
		}
	}
}

void display(struct node *task1)
{
	if ( task1 != NULL ) {
		display(task1 -> left );
		printf("%d\t",task1-> data);
		display(task1 -> right);
	}
}
	 
			
