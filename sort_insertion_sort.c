#include<stdio.h>
void insertion_sort(int[],int);
void main()
{
	int arr[]={14,25,25,1,52,56,48,96,8,53,5,2};
	int arrlen=sizeof(arr)/sizeof(int);
	insertion_sort(arr,arrlen);
	printf("\n");
}

void insertion_sort(int arr[],int len)
{
	int i,j,temp,temp1;
	for(i=1;i<len;i++)
	{
		temp=arr[i];
		for(j=(i-1);j>=0&& temp<arr[j];j--)
			arr[j+1]=arr[j];
		arr[j+1]=temp;
	}


	for(i=0;i<len;i++)
	{
		printf("%d\t",arr[i]);
	}
}
