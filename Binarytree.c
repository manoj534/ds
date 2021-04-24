#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};

struct node* insert();
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);
struct node* sort(struct node *);

struct node *root = NULL;
int main()
{
	int element;
	while ( 1 ) {
		printf("enter 1 for insert\n");
		printf("enter 2 for inorder\n");
		printf("enter 3 for preoredr\n");
		printf("enter 4 for postorder\n");
		printf("enter 5 for exit\n");
		printf("enter 6 for sort\n");
		scanf("%d",&element);
		switch ( element ) {
			case 1:
				root = insert( );
				break;
			case 2:
				if ( root != NULL ) {
					inorder(root);
				} else {
					printf("not possible\n");
				}
				break;
			case 3:
				if ( root != NULL ) {
					preorder(root);
				} else {
					printf("not possible\n");
				}
				break;
			case 4:
				if ( root != NULL ) {
					postorder(root);
				} else {
					printf("not possible\n");
				}
				break;
			case 5:
				exit(1);
			case 6:
				if ( root != NULL ) {
					sort(root);
				} else {
					printf("not possible\n");
				}
				break;
			default :
				printf(" invalid option\n");
		}
	}
}

struct node* insert( ) {
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("enter the data\n");
	scanf("%d",&temp -> data);
	temp -> left = NULL;
	temp -> right = NULL;
	if ( temp -> data == -1)
		return NULL;
	printf("enter the data for left node\n");
	temp -> left = insert();
	printf("enter the right child\n");
	temp -> right = insert();
	root = temp;
	
}

void inorder(struct node *task1)
{
	if ( task1 != NULL ) {
		inorder(task1 -> left );
		printf("%d\t",task1-> data);
		inorder(task1 -> right);
	}
}

void preorder(struct node *task1)
{
	if ( task1 != NULL ) {
		printf("%d\t",task1 -> data);
		preorder(task1-> left);
		preorder(task1-> right);
	}
}

void postorder(struct node *task1)
{
	if ( task1 != NULL ) {
		postorder(task1-> left );
		postorder(task1 -> right);
		printf("%d\t",task1-> data);
	}
}

struct node* sort(struct node *temp)
{
	int s;
	if ( temp ->left != NULL){
		temp -> left= sort(temp -> left);
		if ( temp -> data < temp -> left -> data ) {
			s = temp -> data;
			temp -> data = temp -> left -> data;
			temp -> left -> data = s;
		}
		
	}else {
		return temp;
	}

	 if (temp -> right != NULL ){
			temp -> right = sort (temp -> right);
			if ( temp -> data > temp -> right -> data) {
				s = temp -> data;
				temp -> data = temp -> right -> data;
				temp -> right -> data = s;
			}
	/*		if ( temp -> right -> data > root -> data ) {
				s = temp -> right -> data;
				temp -> right -> data = root -> data;
				root -> data = s;
		}*/ 

	}
	else {
		return temp;
	} 	
	root = temp;
}
