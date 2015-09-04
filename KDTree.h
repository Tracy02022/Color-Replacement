//Ming Chen &Dongyu Li
#include<iostream>
using namespace std;
#include <fstream>
#include <string>
using std::cout;
using std::cin;
using std::cerr;
//The struct of pixel
struct Pixel
{
	unsigned char red,green,blue;
	Pixel(unsigned char r=0,unsigned char g=0,unsigned char b=0)
	{
		red=r;green=g;blue=b;
	}
};
//The KDTree to store nodes
class KDTree
{
	private:
		class TreeNode
		{
			friend class KDTree;
			Pixel value;
			TreeNode *left;
			TreeNode *right;
			TreeNode(Pixel value1, TreeNode *left1 = NULL,
				TreeNode *right1 = NULL)
			{
				value = value1;
				left = left1;
				right = right1;
			}
		};
	TreeNode *root;
	TreeNode *curr_node;
	int NodeNum;
	int ChangeColorNum;
	static const int depth=0;
	void destroySubtree(TreeNode *);

 public:
	 KDTree();
	//accessor methods to get depth of the tree
	static const int GetD()
	 {
		 return depth;
	 }
	// Pointer to the root of the tree
	inline TreeNode *&GetNode()
	 {
		 return root;
	 }
	int Node()const;
	int GetNumNode()const;
	int Dep(TreeNode *n);
	int GetHeight();
	int GetChangedPixNum()const; 
	Pixel* insert(Pixel, TreeNode *&,int);
    void ChangeColor(Pixel,Pixel,TreeNode*,int);
	~KDTree();	
};

