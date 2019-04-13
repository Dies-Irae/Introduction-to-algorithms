#include <iostream>
using namespace std;
class Tree
{
public:
	Tree(int value, Tree *p) : val(value), rChild(nullptr), lChild(nullptr), parent(p) {}
	Tree *treeSearch(int value);
	void treePreWalk();
	Tree *treeMax();
	Tree *treeMin();
	void treeInsert(int value);
	void treeDelete();
	Tree *treeParent() { return parent; }
	int val;

private:
	Tree * lChild;
	Tree *rChild;
	Tree *parent;
};
Tree *Tree::treeSearch(int value)
{
	if (val == value || this == nullptr)
		return this;
	else
	{
		if (value < val)
			return lChild->treeSearch(value);
		else
			return rChild->treeSearch(value);
	}
}
void Tree::treePreWalk()
{
	if (this == nullptr)
		return;
	cout << val << " ";
	lChild->treePreWalk();
	rChild->treePreWalk();
}
Tree *Tree::treeMax()
{
	if (this == nullptr)
		return 0;
	Tree *node = this;
	while (node->rChild != nullptr)
	{
		node = node->rChild;
	}
	return node;
}
Tree *Tree::treeMin()
{
	if (this == nullptr)
		return 0;
	Tree *node = this;
	while (node->lChild != nullptr)
	{
		node = node->lChild;
	}
	return node;
}
void Tree::treeInsert(int value)
{
	if (value > val)
	{
		if (rChild == nullptr)
		{
			rChild = new Tree(value, this);

		}
		else
			rChild->treeInsert(value);
	}
	else
	{
		if (lChild == nullptr)
		{
			lChild = new Tree(value, this);
		}
		else
			lChild->treeInsert(value);
	}
}
void Tree::treeDelete()
{
    /*delete Root is not permitted*/
	if (this == nullptr)
		return;
	else if (rChild == nullptr && lChild == nullptr) //no children
	{
		if (parent->rChild == this)
			parent->rChild = nullptr;
		else
			parent->lChild = nullptr;
		delete this;
	}
	else if (rChild == nullptr) //only right child
	{
		//edit parent's child
		if (parent->rChild == this)
			parent->rChild = lChild;
		else
			parent->lChild = lChild;
		//edit child's parent
		lChild->parent = parent;
		delete this;
	}
	else if (lChild == nullptr) //only left child
	{
		//edit parent's child
		if (parent->rChild == this)
			parent->rChild = rChild;
		else
			parent->lChild = rChild;
		//edit child's parent
		rChild->parent = parent;

		delete this;
	}
	else //two children
	{
		//new successor will be the smallest one in right subtree(or largest one in left subtree)
		Tree *successor = rChild->treeMin();
		//successor is not his parent's child from now
		if (successor->parent->rChild == successor)
			successor->parent->rChild = nullptr;
		else
			successor->parent->lChild = nullptr;
		//edit parent's child
		if (parent->rChild == this)
			parent->rChild = successor;
		else
			parent->lChild = successor;
		//successor become new parent
		successor->rChild = rChild;
		successor->lChild = lChild;

		//edit children's parent
		lChild->parent = successor;
		if(rChild != nullptr)//successor might be the right child of deleted node
			rChild->parent = successor;

		//successor have new parent
		successor->parent = parent;
		delete this;
	}
}
int main()
{
	Tree * root = new Tree(53, nullptr);
	root->treeInsert(17);
	root->treeInsert(78);
	root->treeInsert(9);
	root->treeInsert(45);
	root->treeInsert(65);
	root->treeInsert(87);
	root->treeInsert(23);
	root->treePreWalk();
	cout << endl << root->treeMax()->val << endl;
	cout << root->treeMin()->val << endl;
	//delete leaf node
	root->treeMin()->treeDelete();
	root->treePreWalk();
	root->treeInsert(9);
	//delete parent node with single child
	root->treeSearch(45)->treeDelete();
	cout << endl;
	root->treePreWalk();
	root->treeInsert(45);
	//delete parent node with two child
	root->treeSearch(78)->treeDelete();
	cout << endl;
	root->treePreWalk();
}