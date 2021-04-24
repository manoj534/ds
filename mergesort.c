#include <stdio.h>
#define SIZE 10

int merge(int *, int ,int ,int );
int mergsort(int *,int ,int );
int temp[SIZE];
int main()
{
	int arr[SIZE];
	int elements;
	int i;
	printf("enter the element value\n");
	scanf("%d",&elements);
	for ( i = 0; i < elements; i++){
		scanf("%d",&arr[i]);
	}
	mergsort(arr,0,elements-1);
	for ( i = 0; i < elements; i++ ) {
		printf("%d\t",arr[i]);
	}
}

int mergsort(int *a, int lb, int ub)
{
	if ( lb < ub ) {
		int mid = (lb+ub)/2;
		mergsort(a, lb, mid);
		mergsort(a, mid+1, ub);
		merge(a,lb,mid,ub);
	}
}

int merge(int *a, int lb, int mid, int ub)
{
	int i = lb;
	int k = lb;
	int j = mid + 1;
	while ( i <= mid && j <= ub ) {
		if ( a[i] <= a[j] ) {
			temp[k] = a[i];
			i++;
			k++;
		}else {
			temp[k] = a[j];
			j++;
			k++;
		}
	}
	if ( i > mid ) {
		while ( j <= ub ) {
			temp[k] = a[j];
			j++;
			k++;
		}
	} else {
		while ( i <= mid ) {
			temp[k] = a[i];
			i++;
			k++;
		}
	}
	for ( k = lb; k <= ub; k++ ) {
		a[k] = temp[k];
	}
	//printf("\n");

}
