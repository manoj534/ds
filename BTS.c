#include <stdio.h>
#include <stdlib.h>


struct node {
	int data;
	struct node *left;
	struct node *right;
};
int i = 0;
struct node *front = NULL;
struct node *rear = NULL;

struct node* insert(struct node *,int );
struct node* delete(struct node *,int );
struct node* inorder(struct node *);
void maximum(struct node *);
void minimum1(struct node *);
void search(struct node *,int );
int height(struct node *);
int max(int,int);
void level(struct node *);
int main()
{
	int element;
	int data;
	int ddata;
	int num;
	struct node *root = NULL;
	while ( 1 ) {
		printf("enter 1 for insert data\n");
		printf("enter 2 for delete the element\n");
		printf("enter 3 for inoredre\n");
		printf("enter 4 for exit\n");
		printf("enter 5 for minimum vale in list\n");
		printf("enter 6 for maxmum value in list\n");
		printf("enter 7 to search the element\n");
		printf("enter 8 to find the height of tree\n");
		scanf("%d",&element);
		switch ( element ) {
			case 1:
				printf("enter the data\n");
				scanf("%d",&data);
				root = insert(root,data);
				break;
			case 2:
				printf("enter the data which is present in the list to delete\n");
				scanf("%d",&ddata);
				root = delete(root,ddata);
				break;
			case 3:
				inorder(root);
				break;
			case 4:
				exit(1);
			case 5:
				minimum1(root);
				break;
			case 6:
				maximum(root);
				break;
			case 7:
		//		int num;
				printf("enter the element that you want to search in list\n");
				scanf("%d",&num);
				search(root,num);
				break;
			case 8:
				printf("%d",height(root));
				break;
			case 9:
				level(root);
				break;
			default:
				printf("invalid option\n");
		}
	}

}
int max(int a,int b)
{
	return a>b? a: b;
}

struct node* insert(struct node *root, int key)
{
	if ( root == NULL ) {
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp -> data = key;
	temp -> left = NULL;
	temp -> right = NULL;
//	if ( root == NULL ) {
		return temp;
	} 
	 if ( key < root -> data ) {
		root -> left =insert( root -> left,key);
	} else {
		root -> right = insert(root -> right,key);
	}
	return root;
}
struct node* minimum(struct node *task1)
{
	struct node *current = task1;
	while ( current -> left != NULL ) {
		current = current -> left;
	}
	return current;
}
struct node* delete(struct node *root,int key)
{
	if ( root == NULL ) {
		return root;	
	}
	if ( key < root -> data ) {
		root -> left = delete(root -> left,key);
	} else if ( key > root -> data ) {
		root -> right = delete(root -> right,key);
	} else {
		if ( root -> left == NULL){
			struct node *temp = root -> right;
			free(root);
			return temp;
		} else if ( root -> right == NULL ) {
			struct node *temp = root -> left;
			free(root);
			return temp;
		}
		struct node *task1= minimum(root -> right);
		root -> data = task1 -> data;
		root -> right = delete(root -> right,task1 -> data);
	}
	return root;

}
struct node* inorder(struct node *task1)
{
	if ( task1 != NULL ) {
		inorder(task1 -> left );
		printf("%d\t",task1-> data);
		inorder(task1 -> right);
	}
}

void minimum1(struct node *task1)
{
	if ( task1 -> left == NULL ) {
		printf("%d",task1-> data);
	} else {
		minimum1(task1->left);
	}
}

void maximum(struct node *task1) 
{
	if ( task1 -> right == NULL ) {
		printf("%d",task1 -> data);
	} else {
		maximum(task1 -> right);
	}
}

void search(struct node *task1,int key) {
	if ( task1 == NULL ) {
		printf("key element is not in the list\n");
	} else if ( key < task1 -> data ) {
			search(task1 -> left,key ) ;
	} else if ( key > task1 -> data ) {
			search(task1 -> right,key);
	} else {
		printf("element is in list \n");
	}
}

int height(struct node *task1) {
	int a;
	int b;
	if ( task1 == NULL ) {
		return 0;
	}else{
		a = height(task1 -> left);
		b = height(task1 -> right);
		return max(a,b)+1;
	}
}

void enqueue(struct node *task1 )
{
	printf("hi enqueue\n");
	if ( front == rear ) {
		front = rear = task1;
	} else {
		rear -> right = task1 ;
		task1 -> left = rear;
		rear = task1;
	}
}

struct node* dequeue( ) {
	printf("hi dequeue\n");
	struct node *temp = NULL;
	if ( front == rear ) {
		return NULL ;
	} else {
		temp = front;
		front = front -> right;
		return temp;
	}
}

void level(struct node *root)
{
	struct node *a;
	if ( i == 0 ){
		if ( root == NULL ) {
			return;
		} else {
			enqueue(root);
		}
	}
	printf("hello\n");
	a = dequeue();
	printf("%p",a);
	if ( a ) {
		printf("hi");
		printf( "%d",a-> data);
		if ( a-> left != NULL ) {
			enqueue( a -> left );
		} 
		if ( a -> right != NULL ) {
			enqueue( a -> right ) ;
		}
	}
}	
		
