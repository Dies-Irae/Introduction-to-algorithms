#include <iostream>
using namespace std;
class Stack
{
public:
    Stack(int maxSize);
    ~Stack() {delete head;}
    bool empty();
    int pop();
    void push(int elem);
    int top();

private:
    int *head;
    int *topPtr;
    int mSize;
};
Stack :: Stack(int maxSize)
{
    head = new int[maxSize];
    topPtr = head - 1;
    mSize = maxSize;
}
bool Stack :: empty()
{
    bool ept = (topPtr<head);
    return ept;
}
int Stack :: pop()
{
    if(empty())
    {
        cerr<<"Invalid opreation: \"Pop on a empty stack\""<<endl;
        exit(-1);
    }
    else
    {
        return *(topPtr--);
    }
    
}
void Stack :: push(int elem)
{
    if(topPtr-head+1 >= mSize)
    {
        cerr<<"Invalid opreation: \"Push on a full stack\""<<endl;
        exit(-1);
    }
    else
    {
        *(++topPtr) = elem;
    }
    
}
int Stack :: top()
{
    if(!empty())
    {
        return *topPtr;
    }
    else
    {
        cerr<<"Warning: No elements in stack"<<endl;
        return 0;
    }
}
int main()
{
    Stack s(10);
    for(int i=0; i<10;i++)
    {
        s.push(i);
    }
    while(!s.empty())
    {
        cout<<s.pop()<<endl;
    }
}