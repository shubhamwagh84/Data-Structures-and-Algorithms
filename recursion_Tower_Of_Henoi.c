#include<string.h>
#include <stdio.h>
void main(void);
void TOH(int,char,char,char);
void main()
{
	int num;
	char a='a',b='b',c='c',d;
	printf("enter a number\n");
	scanf("%d",&num);
	TOH(num,a,b,c);
}

void TOH(int n,char a,char b,char c)
{
	if(n>=1)
	{
		TOH(n-1,a,c,b);
		printf("%c to %c \n",a,c);
		TOH(n-1,b,a,c);
	}
}