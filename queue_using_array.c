//Implment queue using array
#include<stdio.h>
#include<stdlib.h>

void enqueue(struct arrayqueue *,int);
int dequeue(struct arrayqueue *,int);
int isfull(struct arrayqueue *);
int isempty(struct arrayqueue *);
struct arrayqueue
{
	int rear,front;
	int capacity;
	int *array;	
};

struct arrayqueue * createqueue(int cap)
{
	struct arrayqueue *queue;
	queue=(struct arrayqueue *) malloc(sizeof(arrayqueue));
	queue->rear=-1;
	queue->front=-1;
	queue->capacity=cap;
	queue->array=(int*)malloc(sizeof(int)*cap);
	return(queue);
}

void enqueue(struct arrayqueue *queue,int value)
{
	if(!isfull(queue))
	{	
		if(queue->front==-1)
		{
			queue->front++;
		}
		queue->rear++;
		queue->array[queue->rear]=value;
	}
	else
		printf("stack is full value is not insrted\n");
}

int dequeue(struct arrayqueue *queue)
{
	int value;
	if(!isempty(queue))
	{
		value=queue->array[queue->front];
		if(queue->rear==queue->front && queue->rear!=(queue->capacity-1))
		{
			queue->rear--;
		}
		queue->front++;
		if(queue->front==queue->capacity)
			queue->front=-1;
		return(value);
	}
	else
		return -1;
}

int isfull(struct arrayqueue *queue)
{
	if(queue->rear==(queue->capacity-1))
		return 1;
	else
		return 0;
}


int isempty(struct arrayqueue *queue)
{
	if(queue->front==-1) 
		return 1;
	else
		return 0;
}

void showqueue(	struct arrayqueue *queue)
{
	int i;
	if(!isempty(queue))
	{
	for(i=queue->front;i<=queue->rear;i++)
	{
		printf("%d\t",queue->array[i]);
	}
	}
	else
		printf("queue is empty\n");
	printf("\n");
}
int main()
{
	int capp=5,choice,value;
	struct arrayqueue *queue=NULL;
	queue=createqueue(capp);
	while(1)
	{
		printf("Enter Your Choice \n 1.enqueue \n 2.dequeue\n 3.show queue\n 4.exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			printf("enter the value which enter into the queue\n");
			scanf("%d",&value);
			enqueue(queue,value);
			break;

			case 2:
			value=dequeue(queue);
			if(value==-1)
				printf("queue is empty\n");
			else
			printf("dequeue value is %d \n",value); 
			break;

			case 4:
			return 0;

			case 3:
			showqueue(queue);
			break;

			default:
			printf("Your enter incorrect value\n");

		}
	}
}