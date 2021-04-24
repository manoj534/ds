#include <stdio.h>
#include <stdlib.h>

int length();
int push();
int traverse();
int delete();
int appendats();
int appendatany();
int reverse();
int removingduplicates();

struct node
{
	int id;
	struct node *left;
	struct node *right;
};

struct node *root = NULL;

int main()
{
	int element;
	int len = 0;
	while (1) {
		printf("enter 1 for push\n");
		printf("enter 2 for travers\n");
		printf("enter 3 for delete\n");
		printf("enter 4  for length\n");
		printf("enter 5 for append at any location\n");
		printf("enter 6 for append node start of the list\n");
		printf("enter 7 for printing the list in reverse order\n");
		printf("enter 8 to remove duplicates\n");
		printf("enter 10 for exit\n");
		scanf(" %d",&element);
		switch ( element ) {
			case 1:
				push();
				break;
			case 2:
				traverse();
				break;
			case 3:
				delete();
				break;
			case 4:
				len = length();
				printf("%d\n",len);
				break;
			case 5:
				appendatany();
				break;
			case 6:
				appendats();
				break;
			case 7:
				reverse();
				break;
			case 8:
				removingduplicates();
				break;
			case 10:
				exit(1);
			default :
				printf("enterd value is invalid\n");
		}
	}
}

int push()
{
	struct node *temp;
	temp = ( struct node* ) malloc(sizeof(struct node));
	printf("enter the id\n ");
	scanf("%d",&temp->id);
	temp -> left = NULL;
	temp -> right = NULL;
	if ( root == NULL ) {
		root = temp;
	} else {
		struct node *dupl;
		dupl = root;
		while ( dupl -> right != NULL ) {
			 dupl = dupl -> right;
		}
		dupl -> right = temp;
		temp -> left = dupl;
	}

}

int traverse() 
{
	struct node *temp;
	temp = root;
	if ( root == NULL ) {
		printf("list is empty\n");
	} else {
		while ( temp != NULL ) {
			printf("%d\t",temp -> id);
			temp = temp -> right;
		}
	}
}
	
int appendatany()
{
	int loc;
	int i = 1;
	printf("enter the location\n");
	scanf("%d",&loc);
	if ( loc > length() ) {
		printf("invalid location\n");
	} else {
		struct node *temp,*node1,*node2;
		node1 = (struct node*)malloc(sizeof(struct node));
		printf("enter the id\n");
		scanf("%d",&node1->id);
		temp = root;
		while( i < loc ) {
			temp = temp -> right;
			i++;
		}
		node2 = temp -> right;
		temp -> right = node1;
		node1 -> right = node2;
		node2 -> left = node1;
		node1 -> left = temp;
	}
}
int appendats()
{
		struct node *temp;
		temp = (struct node*)malloc(sizeof(struct node));
		printf("enter the id \n");
		scanf("%d",&temp->id);
		temp -> left = NULL;
		temp -> right = NULL;
		temp -> right = root;
		root -> left = temp;
		root = NULL;
		root = temp;
}
		
int delete()
{
	int loc;
	printf("enter the location\n");
	scanf("%d",&loc);
	int i = 1;
	if ( loc > length() ) {
		printf("invalid location\n");
	} else {
		struct node *temp;
		temp = root;
		if ( root == NULL ) {
			printf("list is empty \n");
		} else if ( loc == 1 ) {
			struct node *exa;
			exa = root;
			root = exa -> right;
			exa -> right = NULL;
			root -> left = NULL;
		} else {
			struct node *exa1;
			struct node *exa2;
			exa1 = root;
			while ( i < loc - 1 ) {
				exa1 = exa1 -> right;
				i++;
			}
			exa2 = exa1 -> right;
			exa1 -> right = exa2 -> right;
			exa2 -> right = NULL;
			exa2 -> left = NULL;
		}
	}
}
int reverse()
{
	struct node *temp;
	temp = root;
	if ( root == NULL ) {
		printf("list is empty\n");
	} else {
		while ( temp != NULL ) {
			if ( temp -> right == NULL ) {
				break;
			}
			temp = temp -> right;
		} 
		while ( temp != NULL ) {
			printf("%d\t",temp->id);
			if ( temp -> left == NULL ) {
				break;
			}
			temp = temp -> left;
		}
	}
}
int length()
{
	struct node *temp;
	temp = root;
	int count = 0;
	while ( temp != NULL ) {
		temp = temp -> right;
		count++;
	}
	return count;			
			
		
}	
int removingduplicates()
{
	struct node *temp1,*temp2;
	temp1 = root;
	if ( root == NULL ) {
		printf("list is empty\n");
	} else {
		while ( temp1 != NULL ) {
			temp2 = temp1 -> right;
			while ( temp2 != NULL ) {
				struct node *node1 = NULL,*node2 = NULL;
				if ( temp1->id == temp2->id ) {
					if ( temp2 -> right == NULL ) {
						node1 = temp2 -> left;
						node1 -> right = temp2 -> right;
						temp2 = NULL;
					} else {
						node1 = temp2 -> left;
						node2 = temp2 -> right;
						node1 -> right = node2;
						node2 -> left = node1;
						temp2 = node1 -> right;
					}
				} else {
					temp2 = temp2 -> right;
				}
			}
			temp1 = temp1 -> right;
		}
	}
}
