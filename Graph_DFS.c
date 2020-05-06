#include<stdio.h>
#include<stdlib.h>
struct graph
{
	int vertex,edge;
	int *array;
};
void printg1(struct graph*);
void dfs(struct graph*);

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

void dfs(struct graph *g)
{
	int stack[g->vertex],top=-1,i,j,temp[g->vertex],ele[g->vertex],k;

	for(j=0;j<(g->vertex);j++)
	{
		temp[j]=1;
		stack[j]=0;
	}
	top++;
	stack[top]=0;
	printf("The DFS Traversal is\t");
		while(top!=-1)	
		{
			i=stack[top];
			temp[i]=2;
			top--;
			for(j=0;j<g->vertex;j++)
			{
				if(*(g->array+i*g->vertex+j)==1 && temp[j]==1)
				{
					top++;
					stack[top]=j;
					temp[j]=2;
				}
			}
			temp[i]=3;
		printf("%c\t",i+65);
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
dfs(g);
}