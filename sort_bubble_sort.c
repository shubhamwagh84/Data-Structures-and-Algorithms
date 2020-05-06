#include<stdio.h>
void bubble_sort(int[],int);
void main()
{
	int arr[]={14,25,25,1,52,56,48,96,8,53,5,2};
	int arrlen=sizeof(arr)/sizeof(int);
	bubble_sort(arr,arrlen);
	printf("\n");
}

void bubble_sort(int arr[],int len)
{
	int i,j,temp,flag;
	for(i=0;i<len;i++)
	{
		for(j=0;j<len;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}

	for(i=0;i<len;i++)
	{
		printf("%d\t",arr[i]);
	}
}
