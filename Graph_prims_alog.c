#include<stdio.h>
#include<stdlib.h>
struct graph
{
	int vertex,edge;
	int *array;
};
void printg1(struct graph*);
void prims(struct graph*);
void sort(struct graph *);


struct graph* create()
{
	int i,j;
struct graph *g=(struct graph*)malloc(sizeof(struct graph));
g->vertex=6;
g->edge=9;
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

void prims(struct graph *g)
{
	int arr[g->vertex],q[g->vertex],path[g->vertex],i,j,temp[g->vertex],rear=0,min,key,temp1;
	for(i=0;i<g->vertex;i++)
	{
		q[i]=i;
		path[i]=1111;
		temp[i]=1111;
	}
	path[0]=0;
	printf("\nthe shortest path is:");
	while(rear!=-1)
	{
			min=1111;
		for(i=0;i<g->vertex;i++)
		{
			if(min>=path[i] && q[i]!=-1)
			{
				key=i;
				min=path[i];
			}
		}
		q[key]=-1;
		for(j=0;j<g->vertex;j++)
		{
		if(*(g->array+key*g->vertex+j)!=1111 && *(g->array+key*g->vertex+j)!=0)
			{
			if(*(g->array+key*g->vertex+j)<path[j] && *(g->array+key*g->vertex+j)!=0 && q[j]!=-1)
			{
				path[j]=*(g->array+key*g->vertex+j);
				temp[j]=key;
			}
			}
		}
		temp1=-1;
		for(i=0;i<g->vertex;i++)
		{
			if(q[i]!=-1)
				temp1=0;
		}
		if(temp1==0)
			rear=0;
		else if(temp1==-1)
			rear=-1;
		printf("%d\t",key );
	}
		printf("\n");
		temp1=0;
			for(i=0;i<g->vertex;i++)
		{
			temp1=temp1+path[i];
		}
		printf("The Minimum distace of graph is %d\n",temp1);
	
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
			int a[6][6]={{0,3,4,1111,1111,1111},
					 	 {3,0,2,7,4,1111},
						 {4,2,0,5,1111,1111},
					 	 {1111,7,5,0,2,1},
					 	 {1111,4,1111,2,0,6},
					 	 {1111,1111,1111,1,6,0}};
for(i=0;i<(g->vertex);i++)
{
	for(j=0;j<(g->vertex);j++)
	{
		*(g->array+i*g->vertex+j)=a[i][j];
	}
}
printf("The given graph is\n");
printg1(g);
prims(g);
}