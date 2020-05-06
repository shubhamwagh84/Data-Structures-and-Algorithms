#include<stdio.h>
#include<stdlib.h>
struct graph
{
	int vertex,edge;
	int *array;
};
void printg1(struct graph*);
void bfs(struct graph*);

struct graph* create()
{
	int i,j;
struct graph *g=(struct graph*)malloc(sizeof(struct graph));
g->vertex=6;
g->edge=6;
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
for(i=0;i<(g->vertex);i++)
{
	for(j=0;j<(g->vertex);j++)
	{
		printf("%7d\t",*(g->array+i*g->vertex+j));
	}
	printf("\n");
}

}

void bfs(struct graph *g)
{
	int queue[6],front=-1,rear=-1,i,j,temp[6];
	for(j=0;j<(g->vertex);j++)
	{
		temp[j]=1;
		queue[j]=0;
	}
	rear++;
	queue[rear]=0;
		while(front!=rear)
		{
		front++;
		i=queue[front];
		temp[i]=2;
		for(j=0;j<(g->vertex);j++)
		{
			if(*(g->array+i*g->vertex+j)==1 && temp[j]==1)
			{
				rear++;
				queue[rear]=j;
				temp[j]=2;
			}
		}
		temp[i]=3;
		}
		printf("The Graph Traveral in BFS is\t");
		for(j=0;j<(g->vertex);j++)
		{
			printf("%c\t",queue[j]+65);
		}
		printf("\n");		
}




void main()
{
	struct graph *g=create();
	int i,j;
		int a[6][6]={{1,1,1,0,1,0},
					 {1,1,0,1,0,1},
					 {1,0,1,1,1,0},
					 {0,1,1,1,1,1},
					 {1,0,1,1,1,1},
					 {0,1,0,1,1,1}};
for(i=0;i<(g->vertex);i++)
{
	for(j=0;j<(g->vertex);j++)
	{
		*(g->array+i*g->vertex+j)=a[i][j];
	}
}
printg1(g);
bfs(g);
}