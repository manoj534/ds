#include <stdio.h>

int selectionsort(int *arr,int size)
{
	int i;
	int j;
	int temp;
	int min;
	for ( i = 0; i < size; i++) {
		min = i;
		for ( j = i +1; j < size; j++ ) {
			if ( *(arr + j) < *(arr + min ) ) {
				min = j ;
			}
		}
		temp = *(arr + i ) ;
		*(arr + i ) = *(arr + min ) ;
		*(arr + min ) = temp;
	}
	return *arr;
}
