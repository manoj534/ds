#include <stdio.h>
#include "header.h"

int main()
{
	int arr[20];
	int size;
	int i;
	printf("enter the size ");
	scanf("%d",&size);
	for ( i = 0; i < size; i++ ) {
		printf("enter %d element",i);
		scanf("%d",&arr[i]);
	}
	insertionsort(arr,size);
	for ( i = 0; i < size; i++ ) {
		printf("%d\t",arr[i]);
	}
	return 0;
}


	
