#include<stdio.h>
#include<stdlib.h>
struct lltree
{
	int info;
	struct lltree *left,*right;	
};
void levelorder(struct lltree *);
void levelorder1(struct lltree *);
	struct lltree *root=NULL;

struct lltree* cretenode(int value)
{
	struct lltree *tree;
	tree=(struct lltree *)malloc(sizeof(struct lltree));	
	tree->info=value;
	tree->left=NULL;
	tree->right=NULL;
	if(root==NULL)
		root=tree;
	return(tree);
}


int main()
{
		struct lltree *tree,*left1,*right1;
		if(root==NULL)
		tree=cretenode(1);
		root->left=cretenode(2);
		root->right=cretenode(3);
		left1=root->left;
		right1=root->right;
		left1->left=cretenode(4);
		left1->right=cretenode(5);
		right1->left=cretenode(6);
		right1->right=cretenode(7);	
		levelorder(root);
		printf("\n");
}


void levelorder(struct lltree *root)
{
	struct lltree *temp[10];	
	int front=-1,rear=-1;
	if(root!=NULL)
	{
	front++;
	temp[front]=root;
	}

	while(rear!=front)
	{
		rear++;
		printf("%d \t",temp[rear]->info);

		if(temp[rear]->left!=NULL)
		{
			front++;
			temp[front]=temp[rear]->left;
		}
		if(temp[rear]->right!=NULL)
		{
			front++;
			temp[front]=temp[rear]->right;
		}
	}
}