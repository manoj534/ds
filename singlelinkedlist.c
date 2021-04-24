#include <stdio.h>
#include <stdlib.h>

int reverse();
int push();
int traverse();
int length();
int sappend();
int addafter();
int delete();
void deleteatparticular();
void insertafter_before();
void insertafter_beforenumber();
void deleteafter_beforenumber();

struct node {
	int data;
	struct node *link;
};

struct node *root;

int main()
{
	int element;
	int value;
	while(1) {
		printf("enter 1 to insert at the node at the end \n");
		printf("enter 2 for display\n");
		printf("enter 3 to find the length\n");
		printf("enter 4 to append the node at the start of the list\n");
		printf("enter 5 to add the node after a particular node\n");
		printf("enter 6 to delete node at  location\n");
		printf("enter 7 to delete a particular node\n");
		printf("enter 8 to reverse the list\n");
		printf("enter 9 to insert at after / before particular position\n");
		printf("enter 10 to insert at after / before a given number\n");
		printf("enter 11 to delete node after / before a given number\n");
		printf("enter 12 to exit\n");
		scanf("%d",&element);
		switch(element) {
			case 1:
				push();
				break;
			case 2:
				if ( root != NULL ) {
					traverse();
				} else {
					printf("not possible\n");
				}
				break;
			case 3:
				if ( root != NULL ) {
					length();
				} else {
					printf("not possible\n");
				}
				break;
			case 4:
				if ( root != NULL ) {
					sappend();
				} else {
					printf("not possible\n");
				}
				break;
			case 5:
				if ( root != NULL ) {
					addafter();
				} else {
					printf("not possible\n");
				}
				break;
			case 6:
				if ( root != NULL ) {	
					delete();
				} else {
					printf("not possible\n");
				}
				break;
			case 7:
				if ( root != NULL ) {
					deleteatparticular();
				} else {
					printf("not possible\n");
				}
				break;
			case 8:
				if ( root != NULL ) {
					reverse();
				} else {
					printf("not possible\n");
				}
				break;
			case 9:
				if ( root != NULL ) {
					insertafter_before();
				} else {
					printf("not possible\n");
				}
				break;
			case 10:
				if ( root != NULL ) {
					insertafter_beforenumber();
				} else {
					printf("not possible\n");
				}
				break;
			case 11:
				if ( root != NULL ) {
					deleteafter_beforenumber();
				} else {
					printf("not possible\n");
				}
				break;
			case 12:
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
	if ( root == NULL ) {
		root = temp;
	} else {
		struct node *p;
		p = root;
		while ( p -> link != NULL ) {
			p = p -> link;
		}
		p -> link = temp;
	}
}

int traverse()
{
	struct node *temp;
	temp = root;
	while ( temp != NULL ) 	{
		printf("%d\t",temp -> data);
		temp = temp ->link;
	}
//	printf("%d",temp->data);
}

int length()
{
	struct node *temp;
	int count = 0;
	temp = root;
	while( temp  != NULL ) {
		count++;
		temp = temp -> link;
	}
	printf("%d\n",count);
	return count;
}

int sappend()
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("enter the data\n");
	scanf("%d",&temp -> data);
	temp -> link = NULL;
	if ( root == NULL ) {
		root = temp;
	} else {
		temp -> link = root;
		root = temp;
	}
	
}
void insertafter_before()
{
	struct node *temp,*next = root;
	int loc ;
	int i = 1;
	temp =(struct node*) malloc(sizeof(struct node));
	printf("enter data\n");
	scanf("%d",&temp -> data);
	temp -> link = NULL;
	printf("enter location\n");
	scanf("%d",&loc);
	if ( loc == 1 ) {
		temp -> link = root ;
		root = temp;
	} else {
		while ( i < loc - 1 ) {
			next = next -> link;
			i++;
		}
		temp -> link = next -> link;
		next -> link = temp;
	}
}
void insertafter_beforenumber()
{
	struct node *temp ,*next = root;
	int loc;
	int num;
	int i = 0;
	printf("enter 1 to insert after the number\n");
	printf("enter 2 to insert before the number\n");
	scanf("%d",&loc);
	printf("enter the number which is present in list\n");
	scanf("%d",&num);
	temp = (struct node*)malloc(sizeof(struct node));
	printf("enter data\n");
	scanf("%d",&temp -> data);
	if ( loc == 1 ) {
			while ( next -> data != num ) {
				next = next -> link;
			}
			temp -> link = next -> link;
			next -> link = temp;
	} else if ( loc == 2 ) {
			if ( root -> data == num ) {
				temp -> link = root;
				root = temp;
			} else {
				while ( next -> link -> data != num ) {
					next = next -> link;
				}
				if ( next -> link -> data == num ) {
					temp -> link = next -> link;
					next -> link = temp;
				}
			}
	} else {
		printf("enter a valid value\n");
	}
}
int addafter()
{
	int loc;
	printf("enter the location value\n");
	scanf("%d",&loc);
	if ( loc > length() ){
		printf("invalid location\n");
	} else {
		int i = 1;
		struct node *temp;
		temp = (struct node*)malloc(sizeof(struct node));
		printf("enter data\n");
		scanf("%d",&temp -> data);
		temp -> link = NULL;
		struct node *p;
		p = root;
		while ( i < loc ) {
			p = p -> link;
			i++;
		}
		temp -> link = p -> link;
		p -> link = temp;
	}
}

int delete()
{
	int loc;
	printf("enter location\n");
	scanf("%d",&loc);
	if ( loc > length() ) {
		printf("invalid location\n");
	} else if (loc == 1) {
			struct node *temp;
			temp = root;
			root = temp -> link;
			temp -> link = NULL;
			free(temp);
	} else {
		struct node *temp,*p;
		temp = root;
		int i = 1;
		while ( i < loc - 1 ) {
			temp = temp -> link;
			i++;
		}
		p = temp -> link;
		temp -> link = p -> link;
		p -> link = NULL;
	}
}

int reverse()
{
	int i = 1;
	int k = 0;
	int temp = 0;
	int j = length() - 1;
	struct node *p,*q;
	p = q = root;
	while ( i < j ) {
		k = 0;
		while ( k < j ) {
			q = q -> link;
			k++;
		}
		temp = p -> data;
		p -> data = q -> data;
		q -> data = temp;
		i++;
		j--;
		q = root;
		p = p -> link;
	}
}


void deleteatparticular()
{
	struct node *temp = root;
	int choice;
	int loc;
	int i = 1;
	printf(" enter 1 to delete the node after that location\n");
	printf("enter 2 to delete the node before that location\n");
	scanf("%d",&choice);
	printf("enter the location:\n");
	scanf("%d",&loc);
	if ( choice == 1 ) {
			if ( loc < length() ) {
				while ( i < loc ) {
					temp = temp -> link;
					i++;
				}
				temp -> link  = temp -> link -> link;
			} else {
				printf("deletion not possible\n");
			}
	} else if ( i == 2 ) {
			if ( loc > 1 ) {
				if ( loc != 2 ) {
					struct node *p = root;
					while ( i < loc - 1) {
						temp = temp -> link;
						i++;
						if ( i < loc ) {
							p = p -> link;
						}
					} 
					p -> link = temp -> link;
					temp -> link = NULL;
				} else {
					temp = temp -> link;
					root = temp;
				}
			}
	} else {
		printf ( "invalid value\n");
	}
}

void deleteafter_beforenumber()
{
	struct node *temp = root,*p = root;
	int loc;
	int num;
	int i = 1;
	int j = 0;
	printf("enter 1 to delete the node before the number\n");
	printf("enter 2 to delete the node after the number\n");
	scanf("%d",&loc);
	printf("enter number which is present in the list\n");
	scanf("%d",&num);
	if ( loc == 1 ) {
		if ( root -> data == num ) {
			printf("deletion not possible\n");
		} else if ( root -> link -> data == num ) {
				root = root -> link;
		} else {
			while ( temp -> link -> data != num ) {
				temp = temp -> link;
				if ( temp -> link -> data != num ) {
					p = p -> link;
				}
			}
			if ( temp -> link -> data == num ) {
				p -> link  = temp -> link;
				j = 1;
			}
			if ( j == 0 ) {
				printf("value is not present in the list\n");
			}
		}
	} else if ( loc == 2 ) {
			if ( temp -> data == num ) {
				temp -> link = temp -> link -> link;
			} else {
				while ( temp -> data != num ) {
					temp = temp -> link;
				}
				if ( temp -> data == num ) {
					temp -> link = temp -> link -> link;
					j = 1;
				}
				if ( j == 0 ) {
					printf("value not present in the list\n");
				}
			}
	} else {
		printf("choose the rigth operation\n");
	}
}	
							
