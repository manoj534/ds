#include <stdio.h>
#define SIZE 10


int swap(int *,int ,int);
int Quicksort(int *,int ,int );
int partion(int *,int ,int );
int main()
{
	int a[SIZE];
	int i;
	int elements;
	printf("enter the number of elements to eneter\n");
	scanf("%d\n",&elements);
	for ( i = 0; i < elements; i++ ) {
		scanf("%d",&a[i]);
	}
	Quicksort(a,0,elements-1);
	for ( i = 0; i < elements; i++ ) {
		printf("%d\t",a[i]);
	}	
}

int Quicksort(int a[], int lb, int ub)
{
	if ( lb < ub ) {
		int start = lb;
		int end = ub;
		int loc = 0;
		loc = partion(a,start,end);
		Quicksort(a,lb,loc-1);
		Quicksort(a,loc+1,ub);
	} 

}

int partion(int *a,int start,int end)
{
	int pivot = a[start];
	int st = start;
	while ( start < end ) {
		while ( a[start] <= pivot ) {
			start++;
		}
		while ( a[end] > pivot ) {
			end--;
		}
		if ( start < end ) {
			swap(a,start,end);
		}
	}
	swap(a,st,end);
	return end;
}

int swap(int *a,int st,int end)
{
	int temp;
	temp = a[st];
	a[st] = a[end];
	a[end] = temp;
}
