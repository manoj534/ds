#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};


void insert();
struct node* delete(struct node *,int );
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);
void push(struct node *, struct node *);
void search_key(struct node *,int ,struct node *);
struct node* get_minimumkey(struct node *);

struct node *root = NULL;
struct node *parent = NULL;
struct node *current = NULL;

int main()
{
	int element;
	int data;
	while ( 1 ) {
		printf(" enter 1 for insert\n");
		printf(" enter 2 for delete\n");
		printf(" enter 3 for inorder\n");
		printf(" enter 4 for preoredr\n");
		printf(" enter 5 for postorder\n");
		printf("enter 6 for exit\n");
		printf("\n ENTER YOU CHOICE:\n");
		scanf("%d",&element);
		switch ( element ) {
			case 1:
				insert();
				break;
			case 2:
				printf("enter the data which you want to delete\n");
				scanf("%d",&data);
				root = delete(root,data);
				break;
			case 3:
				inorder(root);
				break;
			case 4:
				preorder(root);
				break;
			case 5:
				postorder(root);
				break;
			case 6:
				exit(1);
			default :
				printf("invalid options\n");
		}
	}
}

void insert()
{
	struct node *temp,*task1 = root;
	temp = ( struct node*) malloc ( sizeof( struct node ));
	printf("enter the data\n");
	scanf("%d",&temp -> data);
	temp -> left = NULL;
	temp -> right = NULL;
	if ( root == NULL ) {
		root = temp;
	} else {
		push(task1,temp);
	}
}

void preorder(struct node *task2)
{
	if ( task2 != NULL ) {
		printf("%d\t",task2->data);
		preorder(task2->left);
		preorder(task2->right);
	}
}

void postorder(struct node *task2)
{
	if ( task2 != NULL ) {
		postorder(task2->left);
		postorder(task2->right);
		printf("%d\t",task2->data);
	}
}
void inorder(struct node *task2)
{
	if ( task2 != NULL ) {
		inorder(task2-> left);
		printf("%d\t",task2-> data);
		inorder(task2->right);
	}
}

void push(struct node *task1,struct node *temp)
{
	struct node *t1 = task1, *t2;
	if ( temp -> data < t1 -> data ) {
		if ( t1 -> left == NULL ) {
			t1 -> left = temp;
		} else {
			t1 = t1 -> left;
			push(t1,temp);
		}
	} else {
		if ( t1 -> right == NULL ) {
			t1 -> right = temp;
		} else {
			t1 = t1 -> right;
			push(t1,temp);
		}
	}
}
void search_key(struct node *current ,int key, struct node *parent)
{
	while ( current != NULL && current -> data != key ) {
		parent = current;
		if ( current -> data > key ) {
			current = current -> left;
		} else {
			current = current -> right;
		}
	}
}

struct node* get_minimumkey(struct node *temp)
{
	struct node *current = temp;
	while ( current && current -> left != NULL ) {
		current = current -> left ;
	} 
	return current;
}

struct node* delete(struct node *root,int key) 
{
	if ( root != NULL ) {
		return root;		
	} 
	if ( key < root -> data ) {
		//root = root -> left;
		root -> left = delete(root -> left,key);
	} else if ( key > root -> data ) {
	//	root = root -> right;
		root -> right = delete(root -> right,key);
	} else {
		if ( root -> left == NULL ) {
			struct node *temp = root -> right;
			free(root);
			return temp;
		} else if ( root -> right == NULL ) {
			struct node *temp = root -> left;
			free(root);
			return temp;
		}
		struct node *temp = get_minimumkey(root-> right);
		root -> data = temp -> data;
		root -> right = delete(root -> right,temp -> data);
	}
	return root;
}

