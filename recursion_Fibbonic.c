#include<stdio.h>
int fib(int);
void main()
{
	int num;
	printf("Enter a number to be serch fibbonacci\n");
	scanf("%d",&num);
	int result=fib(num);
	printf("Result=%d\n",result);
}

int fib(int n)
{
	int result;
	if(n==1 || n==2)
	{
		return(1);
	}	
	else
	{
	result=fib(n-1)+fib(n-2);
	return(result);
	}
}