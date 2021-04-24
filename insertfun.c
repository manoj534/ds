#include <stdio.h>

int insertionsort(int *arr,int size)
{
	int i;
	int j;
	int copy;
	for ( i = 1; i < size; i++ ) {
		copy = *(arr+i);
		j = i - 1;
		for ( j = i - 1;(j >= 0 ) &&(*(arr+j) > copy); j--) {
			*(arr + (j + 1)) = *(arr+j);
		}
		*(arr + (j+1)) = copy ;
	}
	return *arr;
}

