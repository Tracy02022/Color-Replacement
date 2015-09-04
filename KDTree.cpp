//Ming Chen &Dongyu Li
#include"stdafx.h"
#include"KDTree.h"
//constructor to initialize data
KDTree::KDTree()
{
	root = NULL;
	curr_node=NULL;
	NodeNum=0;
	ChangeColorNum=0;
}
int KDTree::Node()const
{
	return NodeNum;
}
//get the number of nodes 
int KDTree::GetNumNode()const
{
	return NodeNum;
}
//Get the height of the tree
int KDTree::Dep(TreeNode *n)
{
	if(!n)
		return -1;
	int h1,h2;
	h1 = Dep(n->left);
	h2 = Dep(n->right);
    return h1>h2 ? h1 + 1 : h2 + 1;
} 
//get the height of the tree
int KDTree::GetHeight()
{
   return Dep(GetNode());
}
//get the number of changed pixels
int KDTree::GetChangedPixNum()const
{
	return ChangeColorNum;
}
//insert nodes in the tree
Pixel *KDTree::insert(Pixel pix, TreeNode *&n,int channel)
{
		if(n==nullptr)
		{
			n=new TreeNode (pix);
			++NodeNum; //Record the number of TreeNode
			return &n->value;
		}
		if(pix.red==n->value.red
			&&pix.green==n->value.green
			&&pix.blue==n->value.blue)
			return &n->value;
		if(channel==0&&pix.red<n->value.red)
			return insert(pix,n->left,(channel+1)%3);
		else if(channel==1&&pix.green<n->value.green)
			return  insert(pix,n->left,(channel+1)%3);
		else if(channel==2&&pix.blue<n->value.blue)
			return	insert(pix,n->left,(channel+1)%3);
		else
			return insert(pix,n->right,(channel+1)%3);	
} 
//Change the color of the target pix(teached by Dr. Gothard)
void KDTree::ChangeColor(Pixel oldpix, Pixel newpix,TreeNode *n,int range)
{
	if(n)
	{
		if (abs(n->value.red-oldpix.red)<=range
			&&abs(n->value.green-oldpix.green)<=range
			&&abs(n->value.blue-oldpix.blue)<=range)
		{
			n->value=newpix;
			ChangeColorNum++;
		}	
		ChangeColor(oldpix,newpix,n->left,range);
		ChangeColor(oldpix,newpix,n->right,range);	
	}
}

//destroy the tree
void KDTree::destroySubtree(TreeNode *node)
{
	 if (!node) return;
	 destroySubtree(node->left);
	 destroySubtree(node->right);
	 delete node;
	 node=nullptr;
 }
KDTree::~KDTree()
{
	destroySubtree(root);
	curr_node=NULL;
}
