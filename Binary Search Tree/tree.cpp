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
    void treeDelete(Tree *node);
    Tree *treeParent() { return parent; }

  private:
    Tree *lChild;
    Tree *rChild;
    Tree *parent;
    int val;
};
Tree *Tree::treeSearch(int value)
{
    if (val = value || this == nullptr)
        return this;
    else
    {
        if (value < val)
            return lChild->treeSearch(value);
        else
            return rChild->treeSearch(value);
    }
}
void Tree ::treePreWalk()
{
    if (this == nullptr)
        return;
    cout << val << " ";
    lChild->treePreWalk();
    rChild->treePreWalk();
}
Tree *Tree ::treeMax()
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
Tree *Tree ::treeMin()
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
void Tree ::treeInsert(int value)
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
    }
}
void Tree ::treeDelete(Tree *node)
{
    if (node == nullptr)
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

        //edit parent's child
        if (parent->rChild == this)
            parent->rChild = successor;
        else
            parent->lChild = successor;
        //edit children's parent
        lChild->parent = successor;
        rChild->parent = successor;
        //successor is not his parent's child from now
        if (successor->parent->rChild == successor)
            successor->parent->rChild = nullptr;
        else
            successor->parent->lChild = nullptr;
        //successor have new parent
        successor->parent = parent;
        delete this;
    }
}
int main()
{
    
}