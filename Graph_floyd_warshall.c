#include<stdio.h>
#include<stdlib.h>
struct graph
{
	int vertex,edge;
	int *array;
};
void printg1(struct graph*);
void floyd_warshal(struct graph*);


struct graph* create()
{
	int i,j;
struct graph *g=(struct graph*)malloc(sizeof(struct graph));
g->vertex=4;
g->edge=4;
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
	char str[3]="INF";
	for(j=0;j<(g->vertex);j++)
	{
		if(*(g->array+i*g->vertex+j)==1111)
		{
			printf("%7s\t",str);
		}
		else
		printf("%7d\t",*(g->array+i*g->vertex+j));
	}
	printf("\n");
}

}

void floyd_warshal(struct graph *g)
{
	int i,j,k,dist[4][4];
		for(i=0;i<g->vertex;i++)
		{
			for(j=0;j<g->vertex;j++)
			{
				dist[i][j]=*(g->array+i*g->vertex+j);
			}
		}

	for(k=0;k<g->vertex;k++)
	{
		for(i=0;i<g->vertex;i++)
		{
			for(j=0;j<g->vertex;j++)
			{
				if(dist[i][k]+dist[k][j]<dist[i][j])
				{
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}
		for(i=0;i<g->vertex;i++)
		{
			for(j=0;j<g->vertex;j++)
			{
				*(g->array+i*g->vertex+j)=dist[i][j];
			}
		}
	
}

void main()
{
	struct graph *g=create();
	int inf=1111,i,j;
	int a[4][4]={{0,5,inf,10},
				{inf,0,3,inf},
				{inf,inf,0,1},
				{inf,inf,inf,0}};
	for(i=0;i<(g->vertex);i++)
	{
		for(j=0;j<(g->vertex);j++)
		{
			*(g->array+i*g->vertex+j)=a[i][j];
		}
	}
	printg1(g);			
	floyd_warshal(g);
	printf("\nThe shortest path is following\n");
	printg1(g);			

}