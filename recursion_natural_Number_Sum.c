#include<string.h>
#include <stdio.h>
void main(void);
int sum(int);
int add(int);
void main()
{
	int num=5;
	char a='a',b='b',c='c',d;
	printf("enter a number\n");
	scanf("%d",&num);
	int result=sum(num);
	printf("result=%d\n",result);
}

int sum(int n)
{
	if(n==1)
		return(1);
	else
	{
	int b=n+sum(n-1);
	return(b);
	}
}