#include <stdio.h>
#include <stdlib.h>

int reverse();
int push();
int traverse();
int length();
int sappend();
int addafter();
int delete();

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
		printf("enter 1 for push\n");
		printf("enter 2 for pop\n");
		printf("enter 3 to find the length\n");
		printf("enter 4 to append the node at the start of the list\n");
		printf("enter 5 to add the node after a particular node\n");
		printf("enter 6 to delete the node\n");
		printf("enter 7 to reverse the list\n");
		printf("enter 10 to exit\n");
		scanf("%d",&element);
		switch(element) {
			case 1:
				push();
				break;
			case 2:
				traverse();
				break;
			case 3:
				length();
				break;
			case 4:
				sappend();
				break;
			case 5:
				addafter();
				break;
			case 6:
				delete();
				break;
			case 7:
				reverse();
				break;
			case 10:
				exit(1);
			default :
				printf("invalid value\n");
		}
	}
}


int push(int value)
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
