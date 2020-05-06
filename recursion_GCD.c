#include<stdio.h>
int gcd(int,int);
void main()
{
	int num1,num2;
	printf("enter the two number of GCD\n");
	scanf("%d %d",&num1,&num2);
	int result=gcd(num1,num2);
	printf("result %d\n",result);
}
int gcd(int num1,int num2)
{
	if(num1==0)
	{
		return(num2);
	}
	if(num2==0)
	{
		return(num1);
	}
	if(num1>num2)
	{
		gcd(num1%num2,num2);
	}
	else
	{
		gcd(num1,num2%num1);
	}
}

