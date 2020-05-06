#include<string.h>
#include <stdio.h>
void main(void);
int fact(int);
int add(int);
void main()
{
	int num=5;
	char a='a',b='b',c='c',d;
	printf("enter a number\n");
	scanf("%d",&num);
	int result=fact(num);
	printf("result=%d\n",result);
}

int fact(int n)
{
	if(n==1)
		return(1);
	else
	{
	int b=n*fact(n-1);
	return(b);
	}
}