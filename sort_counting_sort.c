#include<stdio.h>
void counting_sort(int[],int);

	void counting_sort(int arr[],int arrsize)
{
		int b[arrsize],k=10,temp;
		int c[k],i;
		for(i=0;i<k;i++)
			c[i]=0;
		for(i=0;i<arrsize;i++)
		{
			temp=arr[i];
			c[temp]=c[temp]+1;
		}
		for(i=1;i<k;i++)
		{
			c[i]=c[i]+c[i-1];
		}
		for(i=(arrsize-1);i>=0;i--)
		{
			temp=arr[i];
			c[temp]=c[temp]-1;
			temp=c[temp];
			b[temp]=arr[i];
		}
		for(i=0;i<arrsize;i++)
			printf("%d\t",b[i]);
}


void main()
{
	int i,arrsize;
	printf("Enter the size of array\n");
	scanf("%d",&arrsize);
	int arr[arrsize];
	printf("Enter the element in array in a range of 0-9\n");
	for(i=0;i<arrsize;i++)
	{
		scanf("%d",&arr[i]);
	}
	counting_sort(arr,arrsize);
	printf("\n");
}