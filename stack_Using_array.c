//stack using Array 
#include<stdio.h>
#include<stdlib.h>


struct arraystack
{
	int top,capacity,*array;
};

struct arraystack* createstack(int);
int isfull(struct arraystack*);
int isempty(struct arraystack*);
void push(struct arraystack*);
int pop(struct arraystack*);




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

 void push(struct arraystack *stack)
 {
 	int value;
 	if(!isfull(stack))
 	{
 		printf("insert a number\n");
 		scanf("%d",&value);
 		stack->top++;
 		stack->array[stack->top]=value;
 	}
 	else
 		printf("Stack Overflow\n");
 }

 int pop(struct arraystack *stack)
 {
 	int popvalue;
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
 			printf("%d\t",stack->array[i]);
 		}
 		printf("\n");
 	}
 	else
 		printf("Stack Overflow\n");
 }
/*
void main()
{
	int cap=4,choise,Choise,popele;
 struct arraystack *stack=NULL;
 stack=createstack(4);
 while(1)
 {
 	printf("Choise the option\n 1.Push the element \n 2.Pop the element \n 3.view stack\n 4.Exit \n");
 	scanf("%d",&Choise);
 	switch(Choise)
 	{
 		case 1:
 		push(stack);
 		break;

 		case 2:
 		popele=pop(stack);
 		if(popele==-1)
 			printf("Stack Underflow\n");
 		else
 		printf("pop element is %d\n",popele);
 		break;

 		case 3:
 		showstack(stack);
 		break;

 		case 4:
 		return;
 		break;

 		default:
 		printf("You enter wrong choice\n");

 	}
 	printf("---------------------------------------------------------------\n");
 
 }
}*/