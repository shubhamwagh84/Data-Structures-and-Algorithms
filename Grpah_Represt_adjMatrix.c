#include<stdio.h>
#include<stdlib.h>
struct graph
{
	int vertex,edge;
	int *array;
};
void printg1(struct graph*);
struct graph* create()
{
	int i,j;
struct graph *g=(struct graph*)malloc(sizeof(struct graph));
printf("enter the number of vertex nd edge\n");
scanf("%d %d",&g->vertex,&g->edge);
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



void main()
{
	struct graph *g=create();
}