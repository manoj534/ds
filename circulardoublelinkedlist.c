#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};

void insert_begining();
void traverse();
void insert_end();
void insert_atposition();
void insert_beforeposition();
int length();
void insert_afterposition();
void insert_beforenumber();
void insert_afternumber();
void insert_atmiddle();
void insert_penultimate();
struct node* nodecreate( );
void delete_begining();
void delete_end();
void delete_atposition();
int length();
void delete_beforeposition();
void delete_afterposition();
void delete_beforenumber();
void delete_afternumber();
void delete_middle();
void delete_penultimate();

struct node *head = NULL;
int main()
{
	int elements;
	while ( 1 ) {
		printf("enter 1 for insert node at begining\n");
		printf("enter 2 for insert node at end\n");
		printf("enter 3 for insert at given position\n");
		printf("enter 4 for insert before a given position\n");
		printf("enter 5 for insert before a number\n");
		printf("enter 6 for insert after a number\n");
		printf("enter 7 for insert at middle \n");
		printf("enter 8 for penultimate\n");
		printf("enter 9 to traverse\n");
		printf("enter 10 to exit\n");
		printf("enter 11 delete begining\n");
		printf("enter 12 delete end\n");
		printf("enter 13 to delete at given position\n");
		printf("enter 14 to delete before the location\n");
		printf("enter 15 to delete after the location\n");
		printf("enter 16 to delete before a number\n");
		printf("enter 17 to delete after a number\n");
		printf("enter 18 delete the middle value\n");
		printf("enter 19 to delete penultimate\n");
		printf("enter 20 to display length\n");
		printf("\n\nENTER YOU ARE CHOICE:\n");
		scanf("%d",&elements);
		int len = 0;
		switch ( elements ) {
			case 1:
				insert_begining();
				break;
			case 2:
				insert_end();
				break;
			case 3:
				insert_atposition();
				break;
			case 4:
				insert_afterposition();
				break;
			case 5:
				insert_beforenumber();
				break;
			case 6:
				insert_afternumber();
				break;
			case 7:
				insert_atmiddle();
				break;
			case 8:
				if ( head != NULL ) {
					insert_penultimate();
				} else {
					printf("not possible\n");
				}
				break;
			case 9:
				if ( head != NULL ) {
					traverse();
				} else {
					printf(" list is empty\n");
				}
				break;
			case 10:
				exit(1);
			case 11:
				if ( head != NULL ) {
					delete_begining();
				} else {
					printf("list is empty\n");
				}
				break;
			case 12:
				if ( head != NULL ) {
					delete_end();
				} else {
					printf("list empty\n");
				}
				break;
			case 13:
				if ( head != NULL ) {
					delete_atposition();
				} else {
					printf("list is empty\n");
				}
				break;
			case 14:
				if ( head != NULL ) {
					delete_beforeposition();
				} else {
					printf("list is empty\n");	
				} 
				break;
			case 15:
				if ( head != NULL ) {
					delete_afterposition();
				} else {
					printf("list is empty\n");
				}
				break;
			case 16:
				if ( head != NULL ) {
					delete_beforenumber();
				} else {
					printf("list is empty\n");
				} 
				break;
			case 17:
				if ( head != NULL ) {
					delete_afternumber();
				} else {
					printf("list is empty\n");
				}
				break;
			case 18:
				if ( head != NULL ) {
					delete_middle();
				} else {
					printf("list is empty\n");
				}
				break;
			case 19:
				if ( head != NULL ) {
					delete_penultimate();
				} else {
					printf("list is empty\n");
				}
				break;
			case 20:
				if ( head != NULL ) {
					len = length();
					printf("%d",len);
				} else {
					printf("not possible\n");
				}
				break;
			default :
				printf("enter a valid \n");
		}
	}
}
void delete_middle()
{
	struct node *temp = head;
	int len ;
	int i = 1;
	if ( length() % 2 == 0 ) {
		len = (length() / 2);
	} else {
		len = (length()/2)+1;
	}
	if ( len == 1 ) {
		head -> left -> right = head -> right;
		head -> right -> left = head -> left;
		head = head -> right;
	} else {
		while ( i < len ) {
			temp = temp -> right;
			i++;
		}
		temp -> right -> left = temp -> left ;
		temp -> left -> right = temp -> right;
		
	}
}

void delete_penultimate()
{
	struct node *temp = head;
	if ( temp -> right == head ){
		printf("deletion wont happen\n");
	} /*else if ( temp -> right -> right == head ) {
//		head -> left -> right = head -> right;
		temp -> right -> left = temp -> left;
		temp -> left -> right = temp -> right;
		head = temp;*/
//	else if ( temp -> right 
	else /*if ( temp -> right != head )*/ {
		head -> left -> left -> left -> right = head -> left;
		head -> left -> left = head -> left -> left ->left;
	}
}
void delete_beforenumber()
{
	int num;
	struct node *temp = head,*task2;
	printf("enter the number which is present in list\n");
	scanf("%d",&num);
	while ( temp -> data != num && temp -> right != head ) {
		temp = temp -> right;
	}
	if ( temp -> data == num ) {
		task2 = temp;
	} else {
		return ;
	}
	if ( task2 == head ) {
		printf("deletion not possible\n");
	} else if ( head -> right == task2 ) {
		head -> left -> right = head -> right;
		head -> right -> left = head -> left;
		head = head -> right;
	} else {
		temp -> left -> left -> right = temp;
		temp -> left = temp -> left -> left;

		}
}

void delete_afternumber()
{
	int num;
	struct node *temp = head,*task2;
	printf("enter the number\n");
	scanf("%d",&num);
	while ( temp -> data != num && temp -> right != head) {
		temp = temp -> right;
	}
	if ( temp -> data == num ) {
		task2 = temp;
	} else {
		return ;
	}
	if ( task2 -> right -> right == head ) {
		head -> left -> left -> right = head ;
		head -> left = head -> left -> left;
	} else if ( task2 -> right == head ) {
			printf("deletion not possible\n");
	} else {
		task2 -> right -> right -> left = task2;
		task2 -> right = task2 -> right -> right;
		
	}
}
		
	
void delete_afterposition()
{
	int loc;
	int i = 1;
	struct node *temp = head;
	printf("enter the location\n");
	scanf("%d",&loc);
	if ( loc >= length() ) {
		printf("invalid option\n");
	} else if ( loc == (length() - 1)) {
		head -> left -> left -> right = head;
		head -> left = head -> left -> left;
	} else {
		while ( i < loc ) {	
			temp = temp -> right;
			i++;
		}
		temp -> right -> right -> left = temp;
		temp -> right = temp -> right -> right;
	}
}

void delete_beforeposition()
{
	int loc;
	int i = 1;
	struct node *temp = head;
	printf("enter the location\n");
	scanf("%d",&loc);
	if ( loc == 1 || loc > length()) {
		printf("deletion not possible\n");
	} else if (loc == 2) {
		head -> right -> left = head -> left;
		head -> left -> right = head -> right;
		head = head -> right;
	} else {
		while ( i < loc ) {
			temp = temp -> right;
			i++;
		}
		temp -> left -> left -> right = temp;
		temp -> left = temp -> left -> left;
	}
}
				

		
void delete_atposition()
{
	int loc;
	int i = 1;
	struct node *temp = head;
	printf("enter the location\n");
	scanf("%d",&loc);
	if ( loc == 1 ) {
		if ( temp -> right == head ) {
			head = NULL;
		} else {
			head -> left -> right = head -> right;
			head -> right -> left = head -> left;
			head = head -> right;
		}

	} else if ( loc == length() ) {
//		head -> left = head -> left -> left;
		head -> left -> left -> right = head;
		head -> left = head -> left -> left;
	} else if ( loc < length() ){
		while ( i < loc - 1) {
			temp = temp -> right;
			i++;
		} 
		temp -> right = temp -> right -> right;
		temp -> right -> right -> left = temp ;
	} else {
		printf("entered location is not there\n");
	}
} 
void delete_end()
{
	struct node *temp = head;
	if ( head -> right == temp ) {
		head = NULL;
	} else {
		head -> left -> left -> right = head;
		head -> left = head -> left -> left;
		
	}
}
void delete_begining()
{
	struct node *temp = head,*temp2;
	if ( head == NULL ) {
		printf("list is empty\n");
	} else if ( head -> right == head ) {
			head = NULL;
			printf("list is empty\n");

	} else {
		head -> left -> right = head -> right;
		head -> right -> left = head -> left;
		temp2 = head -> right;
		head -> right = NULL;
		head -> left = NULL;
		head = temp2;
	}
}
void insert_atmiddle()
{
	struct node *temp ,*task1 = head;
	int len ;
	int i = 1;
	temp = nodecreate();
	if ( (length()%2) == 0){
		len = (length()/2);
	} else {
		len = (length()/2)+1;
	} 
	if ( head == NULL ) {
		printf("not posiible\n");
	} else {
		while ( i < len ) {
			task1 = task1 -> right;
			i++;
		}
		temp -> right = task1 -> right;
		temp -> left = task1;
		task1 -> right -> left = temp;
		task1 -> right = temp;
	}
}

void insert_penultimate()
{
	struct node *temp,*task1 = head;
	temp = nodecreate();
	if ( head == NULL ) {
		printf("its not possible\n");
	} else if ( head -> right == head ) {
		temp -> right = head;
		temp -> left = head -> right;
		head -> left = temp;
		head -> right = temp;
		head = temp;
	} else {
		temp -> right = head -> left;
		temp -> left = head -> left -> left;
		head -> left -> left ->right = temp;
		head -> left -> left = temp;
	}
}
void insert_begining()
{
	struct node *temp ,*task1 = head;
	temp = (struct node*)malloc(sizeof ( struct node ));
	scanf("%d",&temp -> data);
	temp -> left = NULL;
	temp -> right = NULL;
	if ( head == NULL ) {
		head = temp;
		head -> right = head;
		head -> left = head -> right;
	} else {
		while ( task1 -> right != head ) {
			task1 = task1 -> right;
		} 
		temp -> right = head;
		temp -> left = task1;
		task1 -> right = temp;
		head -> left = temp;
		head = temp;
	}
}

void insert_end()
{
	struct node *temp,*task1 = head;
	temp =(struct node*)malloc(sizeof(struct node));
	scanf("%d",&temp -> data);
	temp -> left = NULL ;
	temp -> right = NULL;
	if ( head == NULL ) {
		head = temp;
		head -> right = head;
		head -> left = head -> right;
	} else {
		while ( task1 -> right != head ) {
			task1 = task1 -> right;
		}
		
		temp -> right = task1 -> right;
		head -> left = temp;
		task1 -> right = temp;
		temp -> left = task1;
	}
}

struct node* nodecreate()
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("enter data\n");
	scanf("%d",&temp -> data);
	temp -> left = NULL ;
	temp -> right = NULL;
	return temp;
}

void insert_atposition()
{
	int loc;
	int i = 1;
	struct node *temp,*task1 = head;
	temp = nodecreate();
	printf("enter the location \n");
	scanf("%d",&loc);
	if ( head == NULL ) {
		printf("insertion not possible\n");
	} else {
		if ( loc == 1 ) {
			temp -> right = head;
			temp -> left = head -> left ;
			head -> left -> right = temp;
			head -> left = temp;
			head = temp;
		} else if ( loc > length()) {
			printf("not possible\n");
			
		} else {
			while ( i < loc - 1) {
				i++;
				task1 = task1 -> right;	
			}
			temp -> right = task1 -> right;
			task1 -> right -> left = temp;
			temp -> left = task1;
			task1 -> right = temp;
			
		}
	}
}
void insert_afterposition()
{
	int i = 1;
	int loc;
	struct node *temp,*task1 = head;
	temp = nodecreate();
	printf("enter the location\n");
	scanf("%d",&loc);
	if ( loc == length() ) {
		temp -> right = head-> left -> right;
		temp -> left = head-> left;
		head -> left -> right = temp;
		head -> left = temp;
	} else if ( loc > length() ) {
		printf("insertion not possible\n");
	} else {
		while ( i < loc ) {
			i++;	
			task1 = task1 -> right;
		}
		temp -> right = task1 -> right;
		task1 -> right->left = temp;
		task1 -> right = temp;
		temp -> left = task1;
	}
}
	
void insert_beforenumber()
{
	struct node *temp,*task1 = head,*task2;
	int num;
	printf("enter the number\n");
	scanf("%d",&num);
	while ( task1 -> data != num ) {
		task1 = task1 -> right;
	}
	if ( task1 -> data == num ) {
		task2 = task1;
		temp = nodecreate();
	} else {
		printf("value not present\n");
		return;
	}
	if ( task2 == head ) {
		temp -> right = head;
		temp -> left = head -> left;
		head -> left -> right = temp;
		head -> left = temp;
		head = temp;
	} else {
		temp -> right = task2 ;
		temp -> left = task2 -> left;
		task2 -> left -> right = temp;
		task2 -> left = temp;
	}
}
void insert_afternumber()
{
	struct node *temp,*task1 = head,*task2;
	int num;
	printf("enter data\n");
	scanf("%d",&num);
	while ( task1 -> data != num ) {
		task1 = task1 -> right;
	}
	if ( task1 -> data == num ) {
		task2 = task1;
		temp = nodecreate();
	} else {
		printf("not possible\n");
		return;
	}
	if ( task2 == head -> left ) {
		temp -> right = head -> left -> right;
		temp -> left = head -> left;
		head -> left -> right = temp;
		head -> left = temp;
	} else {
		temp -> right = task2 -> right;
		temp -> left = task2;
		task2 -> right -> left = temp;
		task2 -> right = temp;
	}
}
		
int length()
{
	struct node *temp = head;
	int i = 1;
	while ( temp -> right != head ) {
		i++;
		temp = temp -> right;
	}
	return i;
}			
			
void traverse()
{
	struct node *temp = head;
	while ( temp -> right!= head ) {
		printf("%d\t",temp -> data);
		temp = temp -> right;
	}
	printf("%d",temp -> data);
}	
