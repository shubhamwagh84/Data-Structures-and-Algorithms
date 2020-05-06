//stack using Array 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct arraystack
{
	int top,capacity;
	char *array;
};

struct arraystack* createstack(int);
int isfull(struct arraystack*);
int isempty(struct arraystack*);
void push(struct arraystack*,char);
char pop(struct arraystack*);
void postfix(struct arraystack*,char[]);



struct arraystack* createstack(int cap)
{
	struct arraystack *stack;
	stack=malloc(sizeof(struct arraystack));
	stack->top=-1;
	stack->capacity=cap;
	stack->array=malloc(sizeof(int)*stack->capacity);
	return(stack);
}

int isfull(struct arraystack *stack)
{
	if(stack->top==(stack->capacity-1))
		return(1);
	else
		return(0);
}

int isempty(struct arraystack *stack)
{
	if(stack->top==-1)
		return(1);
	else
		return(0);
}

 void push(struct arraystack *stack,char value)
 {
 	if(!isfull(stack))
 	{
 		stack->top++;
 		stack->array[stack->top]=value;
 	}
 	else
 		printf("Stack Overflow\n");
 }

 char pop(struct arraystack *stack)
 {
 	char popvalue;
 	if(!isempty(stack))
 	{
 		popvalue=stack->array[stack->top];
 		stack->top--;
 		return(popvalue);
 	}
 	return(-1);
 }

 void showstack(struct arraystack *stack)
 {
 	int i;
 	if(!isempty(stack))
 	{
 		for(i=0;i<=stack->top;i++)
 		{
 			printf("%c\t",stack->array[i]);
 		}
 		printf("\n");
 	}
 	else
 		printf("Stack Overflow\n");
 }

void main()
{
	char str[50]="A+((B+C)+(D+E)*F)/G";
	struct arraystack *stack=NULL;
	printf("Enter a infix string\n");
	scanf("%s",&str[0]);
	stack=createstack(strlen(str)+2);
	postfix(stack,str);
}

void postfix(struct arraystack *stack,char str[50])
{
	int i,a;
	char popelement=' ';
	char ans[strlen(str)],ans1[strlen(str+2)],j=0;
	strcpy(ans1,str);
	str[0]='(';
	for(i=1;i<=strlen(str);i++)
	{
		str[i]=ans1[i-1];
	}
	str[i-1]=')';	


	for(i=0;i<=strlen(str);i++)
	{
		if(str[i]=='(' || str[i]=='+' || str[i]=='*' || str[i]=='/' || str[i]=='-' || str[i]=='%')
		{
			push(stack,str[i]);
		}
		else if(str[i]==')')
		{
			while(popelement!='(')
			{
				popelement=pop(stack);
				if(popelement=='(')
				{
					a=0;
				}
				else
				{
				ans[j]=popelement;
				j++;
				}
			}
			popelement=' ';
		}
		else
		{
			ans[j]=str[i];
			j++;
		}
	}
		printf("The Postfix of Given String is %s",&ans[0]);
	printf("\n");
}
