#include<stdio.h>
#include<stdlib.h>
void insert();
void insertatstart(void);
void insertatmedium(void);
void insertatend(void);
void delete1(void);
void view();
struct node
{
	int info;
	struct node *prev,*next;
};
	struct node *start=NULL;	

int main()
{
	int choice;
	insert();
	while(1)
	{
	printf("1.insert at begining\n 2.insert at end\n 3.insert at postion\n 4.delete the particular node \n 5.view the list \n 6.exit\n choice the following\n");
	scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			insertatstart();
			break;

			case 2:
			insertatend();
			break;

			case 3:
			insertatmedium();
			break;
		
	  		case 4:
	  		delete1();
			break;

	  		case 5:
	  		view();
			break;

			case 6:
			return 0;
			break;

			default:
			printf("Incorrect Number\n");
		}
		printf("----------------------------------------------------\n");
	}
}

void insert()
{
	struct node *n;
	n=(struct node *)malloc(sizeof(struct node));
	printf("enter a value to be inserted\n");
	scanf("%d",&n->info);
	n->next=NULL;
	n->prev=NULL;
	start=n;
}

void insertatstart()
{
	struct node *n;
	n=(struct node *)malloc(sizeof(struct node));
	printf("enter a value to be inserted\n");
	scanf("%d",&n->info);
	start->prev=n;
	n->next=start;
	start=n;
}


void insertatmedium()
{
	struct node *n,*t,*temp;
	int choice;
	printf("after which value to be insrted\n");
	view();
	scanf("%d",&choice);
	t=start;
		while(t->info!=choice)
		{
			t=t->next;
			if(t->next==NULL && t->info!=choice)
			{				
				printf("Value not Found in the list\n");
				return;
			}

			if(t->next==NULL && t->info==choice)
			{				
				insertatend();
				return;
			}

		}	
	n=(struct node *)malloc(sizeof(struct node));
	printf("enter a value to be inserted\n");
	scanf("%d",&n->info);
	temp=t->next;
	temp->prev=n;
	n->prev=t;
	n->next=t->next;
	t->next=n;
}


void insertatend()
{
	struct node *n;
	struct node *t;	
	n=(struct node *)malloc(sizeof(struct node));
	printf("enter a value to be inserted\n");
	scanf("%d",&n->info);
	t=start;
		while(t->next!=NULL)
		{
			printf("%d\n",t->info);
			t=t->next;
		}
	t->next=n;
	n->prev=t;
	n->next=NULL;

}

void delete1()
{
	struct node *t,*back,*front;
	int value;
	printf("which value to be deleted\n");
	scanf("%d",&value);
	t=start;
	if(start->info==value)
	{
		start=t->next;
		start->prev=NULL;
		free(t);
	}
	else
	{
		while(t->info!=value)
		{
			t=t->next;
			if(t->next==NULL && t->info==value)
			{
				back=t->prev;
				back->next=NULL;
				free(t);
				return;
			}
			if(t->next==NULL && t->info!=value)
			{
				printf("value to be deleted not present in the list\n");
				return;
			}
		}
	back=t->prev;
	front=t->next;
	back->next=front;
	front->prev=back;
	free(t);
	}	
}




void view()
{
	struct node *t;
	if(start==NULL)
		printf("List is empty\n");
	else
	{
		t=start;
		printf("the value is \n");
		while(t->next!=NULL)
		{
			printf("%d\t",t->info);
			t=t->next;
		}
		printf("%d\n",t->info);
	}
}