#include <iostream>
using namespace std;
class Queue
{
private:
    int *q;
    int mSize;
    int *front;
    int *rear;
public:
    Queue(int maxSize);
    ~Queue() {delete q;};
    bool empty();
    bool full();
    void enqueue(int elem);
    int dequeue();
};

Queue::Queue(int maxSize)
{
    mSize = maxSize;
    q = new int[maxSize];
    front = q;
    rear = q;
}
bool Queue :: empty()
{
    if(rear == front)
        return true;
    else
        return false;
}
bool Queue :: full()
{
    if((rear-front+1)%mSize == 0)
        return true;
    else
        return false;
}
void Queue :: enqueue(int elem)
{
    if(full())
    {
        cerr<<"Error: Enqueue on a full queue"<<endl;
        exit(-1);
    }
    else
    {
        *rear = elem;
        rear = (rear-q+1)%mSize + q;
    }
         
}
int Queue :: dequeue()
{
    if(empty())
    {
        cerr<<"Error: Dequeue on a empty queue"<<endl;
        exit(-2);
    }
    else
    {
        int tmp = *front;
        front = q + (front-q+1)%mSize;
        return tmp;
    } 
}
