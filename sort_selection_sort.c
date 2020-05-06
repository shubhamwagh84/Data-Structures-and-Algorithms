#include<stdio.h>
void selection_sort(int[],int);
void main()
{
	int arr[]={14,25,25,1,52,56,48,96,8,53,5,2};
	int arrlen=sizeof(arr)/sizeof(int);
	selection_sort(arr,arrlen);
	printf("\n");
}

void selection_sort(int arr[],int len)
{
	int i,j,min,index,temp;
	for(i=0;i<len;i++)
	{
		min=arr[i];
		index=i;
		for(j=(i+1);j<len;j++)
		{
			if(min>arr[j])
			{
				min=arr[j];
				index=j;
			}
		}
	temp=arr[i];
	arr[i]=arr[index];
	arr[index]=temp;
	}

	for(i=0;i<len;i++)
	{
		printf("%d\t",arr[i]);
	}
}
