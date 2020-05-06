#include<stdio.h>
#include<stdlib.h>
struct lltree
{
	int info;
	struct lltree *left,*right;	
};
void inorder(struct lltree *);

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
		inorder(root);
		printf("\n");		
}


void inorder(struct lltree *root)
{
	if(root!=NULL)
	{
		inorder(root->left);	
		printf("%d\t",root->info);
		inorder(root->right);
	}
}



