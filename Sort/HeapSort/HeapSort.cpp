#include<iostream>
using namespace std;
struct maxHeap{
    //A[0] 储存堆中的元素个数
    private:
    unsigned maxLength;
    int *A = nullptr;
    int *rear = nullptr;

    public:
    maxHeap(unsigned maxHeapLen) : maxLength(maxHeapLen)
    {
        A = new int[maxHeapLen+1];
        A[0] = 0;
        rear = &A[1];
    }

    int size() { return A[0]; }
    int insert(int num);
    int pop();
    int leftChildIndex(int nodeIndex){ return nodeIndex*2; }
    int rightChildIndex(int nodeIndex){ return nodeIndex*2 + 1; }
    int parentIndex(int nodeIndex) { return nodeIndex/2; }
    void maxHeapify(int currentRoot);
    void buldMaxHeap()
    {
        for(int i=size()/2; i>=1; i--)
        {
            maxHeapify(i);
        }
    }
};
void maxHeap :: maxHeapify(int currentRoot)
{
    if(currentRoot >= size())
        return ;
    int l = leftChildIndex(currentRoot);
    int r = rightChildIndex(currentRoot);
    int largestIndex = currentRoot;
    if(l<= size() && A[l] > A[currentRoot])
        largestIndex = l;
    if(r<= size() && A[r] > A[largestIndex])
        largestIndex = r;
    if(currentRoot != largestIndex)
        {
        swap(A[currentRoot],A[largestIndex]);
        maxHeapify(largestIndex);
        }
}
int maxHeap :: insert(int num)
{
    if(size() >= maxLength)
    {
        cerr<<"No available heap space"<<endl;
        return -1;
    }
    *rear = num;
    rear ++;
    A[0] ++;
}
int maxHeap :: pop()
{
    if(size() == 0)
    {
        cerr<<"No elements"<<endl;
        return -1;
    }
    int ans = A[1];
    A[0] --;
    swap(A[1],*rear);
    rear --;
    maxHeapify(1);
    return ans;
}
int main()
{
    int a[] = {5, 13, 2, 25, 7, 17, 20, 8, 4, 1, 2, 3, 4, 7, 8, 9, 10, 14, 16};
    maxHeap heap(sizeof(a)/sizeof(int));
    for(auto i : a)
    {
        heap.insert(i);
    }
    heap.buldMaxHeap();
    while(heap.size() != 0)
    {
        cout<<heap.pop()<<" ";
    }
    return 0;

}