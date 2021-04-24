#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void pushbeforelast();
void pushend();
void display();
void pushstart();
int length();
void pushatloc();
void pushafterloc();
void pushatmiddle();
void penultimate();
void pushafternumber();
void pushbeforeanumber();
void deletebegining();
void deleteend();
void deleteatposition();
void deleteafterposition();
void deletebeforeposition();
void deletemiddle();
void deletepenultimate();
void deletebeforenumber();
void deleteafternumber();

struct node {
	int data;
	struct node *link;
};

struct node *root = NULL;

int main()
{
	int element;
	while ( 1 ) {
		printf("INSERT OPERATIONS:\n\n");
		printf("enter 1 for add at start\n");
		printf("enter 2 for display\n");
		printf("enter 3 to insert at start\n");
		printf("enter 4 to insert at particular position\n");
		printf("enter 5 to insert after a particular position\n");
		printf("enter 6 for length\n");
		printf("enter 7 to insert node at middle\n");
		printf("enter 8 to insert before last node\n");
		printf("enter 9 to insert after a particular number\n");
		printf("enter 10 to insert before a particular number\n\n");
		printf("DELETE OPERATIONS :\n\n");
		printf("enter 11 to delete node at begining\n");
		printf("enter 12 to delete the last node\n");
		printf("enter 13 to delete the particular node\n");
		printf("enter 14 to delete node after particular position\n");
		printf("enter 15 to delete node before the given position\n");
		printf("enter 16 to delete node which is in the middle of the list\n");
		printf("enter 17 to delete node before the given number\n");
		printf("enter 18 to delete node after the given number\n");
		printf("enter 19 to delete penulimate node\n");
		printf("enter 21 for exit\n\n");
		printf("SELECT THE OPERATIONS:\n");
		scanf("%d",&element);
		switch(element) {
			case 1:
				pushend();
				break;
			case 2:
				if ( root != NULL ) {
					display();
				} else {
					printf("not posible\n");
				}
				break;
			case 3:
				if ( root != NULL ) {
					pushstart();
				} else {
					printf("not possible\n");
				}
				break;
			case 4:
				if ( root != NULL ) {
					pushatloc();
				} else {
					printf("not possible\n");
				}
				break;
			case 5:
				if ( root != NULL ) {
					pushafterloc();
				} else {
					printf("not posiible\n");
				}
				break;
			case 6:
				if ( root != NULL ) {
					length();
				} else {
					printf("not possible\n");
				}
				break;
			case 7:
				if ( root != NULL ) {
					pushatmiddle();
				} else {
					printf("not possible\n");
				}
				break;
			case 8:
				if ( root != NULL ) {
					pushbeforelast();
				} else {
					printf("not possible\n");
				}
				break;
			case 9:
				if ( root != NULL ) {
					pushafternumber();
				} else {
					printf("not possible\n");
				}
				break;
			case 10:
				if ( root != NULL ) {
					pushbeforeanumber();
				} else {
					printf("not possible\n");
				}
				break;
			case 11:
				if ( root != NULL ) {
					deletebegining();
				} else {
					printf("not possible\n");
				}
				break;
			case 12:
				if ( root != NULL ) {
					deleteend();
				} else {
					printf("not posiible\n");
				}
				break;
			case 13:
				if ( root != NULL ) {
					deleteatposition();
				} else {
					printf("not possible\n");
				}
				break;
			case 14:
				if ( root != NULL ) {
					deleteafterposition();
				} else {
					printf("not possible\n");
				}
				break;
			case 15:
				if ( root != NULL ) {
					deletebeforeposition();
				} else {
					printf("not possible\n");
				}
				break;
			case 16:
				if ( root != NULL ) {
					deletemiddle();
				} else {
					printf("not possible\n");
				}
				break;
			case 17:
				if ( root != NULL ) {
					deletebeforenumber();
				} else {
					printf("not possible\n");
				}
				break;
			case 18:
				if ( root != NULL ) {
					deleteafternumber();
				} else {
					printf("not possible\n");
				}
				break;
			case 19 :
				if ( root != NULL ) {
					deletepenultimate();	
				} else {
					printf("not possible\n");
				}
				break;
			case 21:
				exit(1);
			default :
				printf("invalid option\n");
		}
	}
}

void deletebegining()
{
	struct node *temp = root -> link;
	if ( root == NULL ) {
		printf("list is empty\n");
	} else if ( temp ->link == root -> link ) {
			root = NULL;
	} else {
		root -> link = root -> link -> link;
	}
}

void deleteend()
{
	struct node *temp = root -> link,*temp1 = root -> link;
	while ( temp -> link != root ) {
		temp = temp -> link;
	}
	if ( temp -> link == root -> link ) {
		root = NULL;
	} else {
		temp -> link = temp1;
		root = temp;
	}
}
		
void deleteatposition()
{
	struct node *temp = root -> link;
	int loc;
	int i = 1;
	printf("enter location\n");
	scanf("%d",&loc);
	if ( loc > length() ) {
		printf("invalid location\n");
	} else if ( loc == length() ) {
			while ( temp -> link != root ) {
				temp = temp -> link;
			}
				temp -> link = root -> link;
				root = temp;
		
	} else if ( loc == 1 ) {
		root -> link = temp -> link;
	} else {
		while ( i < loc - 1 ) {
			 temp = temp -> link;
			i++;
		}
		temp -> link = temp -> link -> link;
	}
}

void deleteafterposition()
{
	struct node *temp = root -> link;
	int loc;
	int i = 1;
	printf("enter the location\n");
	scanf("%d",&loc);
	if ( loc >= length() ) {
		printf("invalid location\n");
	} else {
		while ( i < loc ) {
			temp = temp -> link;
			i++;
		}
		if ( temp -> link == root ) {
			temp -> link = root -> link;
			root = temp;
		} else {
			temp -> link = temp -> link -> link;
		}
	}
}
		
void deletebeforeposition()
{
	struct node *temp = root;
	int loc;
	int i = 1;
	printf("enter the location\n");
	scanf("%d",&loc);
	if ( loc > length() ) {
		printf("invalid location\n");
	} else {
		while ( i < loc - 1 ) {
			temp = temp -> link;
			i++;
		}
		temp -> link = temp -> link -> link;
	}
}

void deletemiddle()
{
	struct node *temp = root -> link;
	int i = 1;
	int loc = ceil(length()/2);
	if ( (length()) % 2 != 0 ) {
		loc = loc + 1;
	} 
	printf("\n\t%d",loc);
	if ( loc > 1  ) {
		while ( i < loc - 1 ) {
			temp = temp -> link;
			i++;
		}
		temp -> link = temp -> link -> link;
	} else {
		root -> link = temp -> link;
	}
}

void deletepenultimate() 
{
	struct node *temp = root;
	if ( temp -> link != root ) {
		while ( temp -> link -> link != root ) {
			temp = temp -> link;
		} 
		temp -> link = temp -> link -> link;
	} else {
		printf(" penultimate not possible\n");
	}
}

void deletebeforenumber()
{
	struct node *next = root;
	int num;
	printf("enter a number\n");
	scanf("%d",&num);
	if ( next -> link != root ) {
		if ( next -> link -> data == num ) {
			printf("no delete occured\n");
		} else {
			while ( next -> link -> link != root ) {
				if ( next -> link -> link -> data == num ) {
					break;
				}
				next = next -> link;
			}
			if ( next -> link -> link == root ) {
				if ( next -> link -> link -> data == num ) {
					next -> link = next -> link -> link;
				}
			}
			 else {
				next -> link = next -> link -> link;
			}
		}
	} else {
		printf("delete wont happen\n");
	}
}

void deleteafternumber()
{
	struct node *temp = root -> link;
	int num;
	printf("enter a number\n");
	scanf("%d",&num);
	if ( temp == root ) {
		printf("deletion not possible\n");
	} else {
		while ( temp -> link != root ) {
			if ( temp -> data == num ) {
				break;
			}
			temp = temp -> link;
		}
		if ( temp -> link == root ) {
			if ( temp -> data == num ) {
				temp -> link = temp -> link -> link;
				root = temp;
			}
		} else {
			temp -> link = temp -> link -> link;
		}
	}
}		
				
		
		
	
void pushend()
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("enter data\n");
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

void pushstart()
{
	struct node *temp;
	temp =(struct node*) malloc(sizeof(struct node));
	printf("enter data\n");
	scanf("%d",&temp -> data);
	temp -> link = NULL;
	if ( root == NULL ) {
		temp -> link = temp;
		root = temp;
	} else {
		temp -> link = root -> link;
		root -> link = temp;
	}
} 

void pushatloc()
{
	struct node *temp,*next = NULL;
	int loc;
	int i = 1;
	next = root -> link;
	printf("enter the location\n");
	scanf("%d",&loc);
	temp = (struct node*)malloc(sizeof(struct node));
	printf("enter data\n");
	scanf("%d",&temp -> data);
	temp -> link = NULL;

	if ( loc > length()) {
		printf("enter a valid ocation\n");
	} else if ( loc == 1 ) {
		temp -> link = next;
		root -> link = temp;
		
	} else {
		while ( i < loc - 1 ) {
			next = next -> link;
			i++;
		}
		temp -> link = next -> link;
		next -> link = temp;
		printf("invalid option\n");
	}
}
void pushbeforeanumber()
{
	struct node *temp,*next1 = NULL,*next = NULL ;
	next = root;
	next1 = root;
	int i = 0;
	int value;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("enter data\n");
	scanf("%d",&temp->data);
	temp -> link = NULL;
	printf("enter value\n");
	scanf("%d",&value);
	while ( next1 -> link -> data != value ) {
		next1 = next1 -> link;
		if ( next1 == root ) {
			break;
		}
	}
	if ( next1 -> link -> data == value ) {
		i = 1;
	}
	if ( root == NULL ) {
		printf("list is empty\n");
	} else {
		if ( i != 0 ) {
			while( next -> link -> data != value) {
					next = next -> link;
			}
			temp -> link = next -> link;
			next -> link = temp;
		} else {
			printf("please enter a valid value\n");
		}			
	}
}
				
		
	
void pushatmiddle()
{
	struct node *temp,*next = NULL;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("enter data\n");
	scanf("%d",&temp -> data);
	next = root -> link;
	temp -> link = NULL;
	if ( root == NULL ) {
		printf("list is empty\n");
	} else {
		int loc = round((length()/2));
		int i = 1;
		while ( i < loc ) {
			next = next -> link;
			i++;
		}
		temp -> link = next -> link;
		next -> link = temp;
	}
}		

void pushafternumber()
{
	struct node *temp,*next;
	next = root -> link;
	int value;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("enter the data in to temp\n");
	scanf("%d",&temp -> data);
	temp -> link = NULL;
	if ( root == NULL ) {
		printf("list is empty\n");
	} else {
		printf("enter the value to search");
		scanf(" %d",&value);
		while ( next -> link != root -> link ) {
				if ( next -> data == value ) {
					temp -> link = next -> link;
					next -> link = temp;
					break;
				}
				next = next -> link;
		}
		if ( root -> data == value ) {
			temp -> link = root -> link;
			root -> link = temp;
			root = temp;
		}
	}
}
			
void pushafterloc()
{
	struct node *temp,*next;
	int loc;
	int i = 1;
	next = root -> link;
	printf("enter the location\n");
	scanf("%d",&loc);
	temp = (struct node*)malloc(sizeof(struct node));
	printf("enter data\n");
	scanf("%d",&temp -> data);
	temp -> link = NULL;
	if ( loc > length() ) {
		printf("enter a valid value\n");
	} else {
		if ( loc < length() ) {
			while ( i < loc ) {
				next = next -> link;
				i++;
			}
			temp -> link = next -> link;	
			next -> link = temp;
		} else { 
			temp -> link = root -> link;
			root -> link = temp;
			root = temp;
		}
	}
}

void pushbeforelast()
{
	struct node *temp,*next = NULL;
	int i = 1;
	next = root -> link;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("enter data\n");
	scanf("%d",&temp -> data);
	temp -> link = NULL;
	if ( root == NULL ) {
		printf("list is empty\n");
	} else {
		int loc = length();
		if ( loc == 1 ) {
			temp -> link = root;
			root -> link = temp;
		} else {
			while ( i < loc - 1 ) {
				next = next -> link;
				i++;
			}
			temp -> link = next -> link;
			next -> link = temp;
		}
	}
}			
void display()
{
	printf("display\n");
	struct node *temp;
	temp = root -> link;
	if ( root == NULL ) {
		printf("list is empty\n");
	} else {
		while( temp -> link != root -> link ) {
			printf("%d\t",temp -> data);
			temp = temp -> link;
		}
		printf("%d\n",temp -> data);
	}
}

int length()
{
	struct node *temp;
	int count = 1;
	temp = root -> link;
	if ( root == NULL ) {
		return 0;
	} else {
		while ( temp -> link != root -> link ) {
			count++;
			temp = temp -> link;
		}
		return count;
	}
}
