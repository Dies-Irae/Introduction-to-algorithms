#include <iostream>
#define red true
#define black false
//true is red, false is black
using namespace std;
class RBNode
{
public:
    RBNode(int val,RBNode* p,bool nodeColor):key(val),parent(p),lChild(nullptr),rChild(nullptr),color(nodeColor) {}
    RBNode* treeSearch(int value);
	void treePreWalk();
	RBNode* treeMax();
	RBNode* treeMin();
	void rbInsert(int elem);
	void rbInsertFixup(RBNode *z);
    int key;
private:
    void leftRotate(RBNode* x);
	void rightRotate(RBNode* x);
    RBNode* lChild;
    RBNode* rChild;
    RBNode* parent;
    bool color;
};
RBNode *RBNode::treeSearch(int value)
{
	if (key == value || this == nullptr)
		return this;
	else
	{
		if (value <= key)
			return lChild->treeSearch(value);
		else
			return rChild->treeSearch(value);
	}
}
void RBNode::treePreWalk()
{
	if (this == nullptr)
		return;
	cout << key << " ";
	lChild->treePreWalk();
	rChild->treePreWalk();
}
RBNode* RBNode::treeMax()
{
	if (this == nullptr)
		return nullptr;
	RBNode *node = this;
	while (node->rChild != nullptr)
	{
		node = node->rChild;
	}
	return node;
}
RBNode* RBNode::treeMin()
{
	if (this == nullptr)
		return nullptr;
	RBNode *node = this;
	while (node->lChild != nullptr)
	{
		node = node->lChild;
	}
	return node;
}
void RBNode::leftRotate(RBNode* x)
{
    RBNode *y = x->parent;
    x->parent = y->parent;
	if(y == y->parent->lChild)
	{
		y->parent->lChild = x;
	}
	else
	{
		y->parent->rChild = x;
	}
	
	if(x->rChild != nullptr)
	{
		x->rChild->parent = y;
	}
	y->lChild = x->rChild;
	x->rChild = y;
	y->parent = x;
    
}
void RBNode :: rightRotate(RBNode* y)
{
	RBNode *x = y->parent;
	y->parent = x->parent;
	if(x == x->parent->lChild)
	{
		x->parent->lChild = y;
	}
	else
	{
		x->parent->rChild = y;
	}
	if(y->lChild != nullptr)
	{
		y->lChild->parent = x;
	}
	x->rChild = y->lChild;
	y->lChild = x;
	x->parent = y;
}
void RBNode :: rbInsert(int elem)
{
	if(elem <= key)
	{
		if(rChild == nullptr)
		{
			rChild = new RBNode(elem,this,red);
			rbInsertFixup(rChild);
		}
		else
			rChild -> rbInsert(elem);
	}
	else
	{
		if(lChild == nullptr)
		{
			lChild = new RBNode(elem,this,red);
			rbInsertFixup(lChild);
		}
		else
			lChild -> rbInsert(elem);
	}
}
void RBNode::rbInsertFixup(RBNode* z)
{
	
}


/* pending */