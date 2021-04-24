#include <stdio.h>
#include "headee.h"


int main()
{
	int arr[20];
	int size;
	int i;
	printf("enter the size ");
	scanf("%d",&size);
	printf("enter the array values");
	for ( i = 0; i < size; i++ ) {
		printf("enter %d element",i);
		scanf("%d",&arr[i]);
	}
	selection(arr,size);
	for ( i = 0; i < n; i++) {
		printf("%d\t",arr[i]);
	}
	return 0;
}
