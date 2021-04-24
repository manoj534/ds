#include <stdio.h>

int binary(int [],int ,int ,int);
int main()
{
	int arr[10];
	int num;
	int key;
        int l = 0;
	int i = 0;
	int pos;
	printf("enter length of array\n");
	scanf("%d",&num);
	printf("enter array elements\n");
	for ( i = 0; i < num; i++ ) {
		scanf("%d",&arr[i]);
	}
	printf("Enter key element\n");
	scanf("%d",&key);
	int r = num;
	pos = binary(arr,key,0,r);
	if(pos != -1 ) {
		printf("%d found at %d\n",key,pos);
	}
	else {
		printf("Element Not found\n");
	}
	return 0;
}

int binary(int arr[],int key,int l,int r)
{
	int mid;
	if(l < r) {
		mid = (l+r)/2;
		if(arr[mid] == key ) {
			return mid+1;
		}
		else if(key < arr[mid]) {
			return binary(arr,key,0,mid-1);
		}
		else {
			return binary(arr,key,mid+1,r);
		}
	}
	return -1; 	
}
