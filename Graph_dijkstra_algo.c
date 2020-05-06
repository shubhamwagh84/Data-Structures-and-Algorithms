#include<stdio.h>
#include<stdlib.h>
struct graph
{
	int vertex,edge;
	int *array;
};
void printg1(struct graph*);
void dijkstra(struct graph*);
void sort(struct graph *);


struct graph* create()
{
	int i,j;
struct graph *g=(struct graph*)malloc(sizeof(struct graph));
g->vertex=5;
g->edge=5;
g->array=(int*)malloc(sizeof(int)*(g->vertex*g->vertex));
for(i=0;i<(g->vertex);i++)
{
	for(j=0;j<(g->vertex);j++)
	{
		*(g->array+i*g->vertex+j)=0;
	}
}
return(g);
} 



void printg1(struct graph* g)
{
int i,j;
char str[]="INF";
for(i=0;i<(g->vertex);i++)
{
	for(j=0;j<(g->vertex);j++)
	{
		if(*(g->array+i*g->vertex+j)==1111)
			printf("%7s\t",&str[0]);
		else
		printf("%7d\t",*(g->array+i*g->vertex+j));
	}
	printf("\n");
}

}

void dijkstra(struct graph *g)
{
	int arr[g->vertex],q[g->vertex],path[g->vertex],i,j,temp[g->vertex],rear=0,min,key,temp1,k;
	printf("Enter a starting vertex\n");
	scanf("%d",&k);
		printf("The shortest distace from %d is\t",k);
	for(i=0;i<g->vertex;i++)
	{
		q[i]=i;
		path[i]=1111;
		arr[i]=i;
	}
	path[k]=0;
	while(rear!=-1)
	{
		min=11111;
	for(i=0;i<g->vertex;i++)
	{
		if(min>path[i] && path[i]!=1111 && q[i]!=-1)
		{
			min=path[i];
			key=i;
		}
	}
	q[key]=-1;		
	for(i=0;i<g->vertex;i++)
	{
		if(*(g->array+key*g->vertex+i)!=1111 && *(g->array+key*g->vertex+i)!=0)
		{
			if(path[i]>path[key]+*(g->array+key*g->vertex+i))
			{
				path[i]=path[key]+*(g->array+key*g->vertex+i);
				temp[i]=key;
			}
		}
	}temp1=-1;
	for(i=0;i<g->vertex;i++)
	{
		if(q[i]!=-1)
			temp1=0;
	}
	if(temp1==-1)
		rear=-1;
	
	printf("%d\t",key);
	}
	temp1=0;
	for(i=0;i<g->vertex;i++)
	{
		temp1=temp1+path[i];
	}
	printf("\n");
	printf("Total distace is %d\n",temp1 );
	printf("\n");

}




void main()
{
	struct graph *g=create();
	int i,j;
/*		int a[6][6]={{1,1,1,0,1,0},
					 {1,1,0,1,0,1},
					 {1,0,1,1,1,0},
					 {0,1,1,1,1,1},
					 {1,0,1,1,1,1},
					 {0,1,0,1,1,1}};
*/
			int a[6][6]={{0,10,5,1111,1111},
					 	 {1111,0,2,1,1111},
						 {1111,3,0,9,2},
					 	 {1111,1111,1111,0,4},
					 	 {7,1111,1111,6,0}};
for(i=0;i<(g->vertex);i++)
{
	for(j=0;j<(g->vertex);j++)
	{
		*(g->array+i*g->vertex+j)=a[i][j];
	}
}
printf("The given graph is\n");
printg1(g);
dijkstra(g);
}