#include<stdio.h>
void quick_sort(int[],int);

void main()
{
	int len;
	printf("how many number to be enter\n");
	scanf("%d",&len);
	int i,arr[len];
	for(i=0;i<len;i++)
	{
		scanf("%d",&arr[i]);
	}
	quick_sort(arr,len);
}

void quick_sort(int arr[],int len)
{
	int stack1[20],stack2[20];
	int top=0;
	int i,beg,end,left,right,loc,temp;
	stack1[top]=0;	
	stack2[top]=len-1;
	while(top!=-1)
	{
		beg=stack1[top];
		end=stack2[top];
		top--;
		left=beg;
		right=end;
		loc=beg;
		while(right!=loc)
		{
			if(arr[loc]<arr[right])
				right--;
			if(arr[loc]>arr[right])
			{
				temp=arr[loc];
				arr[loc]=arr[right];
				arr[right]=temp;
				loc=right;
			}
			if(arr[loc]>arr[left])
				left++;
			if(arr[loc]<arr[left])
			{
				temp=arr[loc];
				arr[loc]=arr[left];
				arr[left]=temp;
				loc=left;
			}
		}
		if((loc-1)-beg>1)
		{
		 	top++;
		stack1[top]=beg;
		stack2[top]=loc-1;
		}
		if(end-(loc+1)>1)
		{
		top++;
		stack1[top]=loc+1;
		stack2[top]=end;
		}		
	}

	for(i=0;i<=(len-1);i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n");
}

