#include <iostream>
using namespace std;
int partition(int *A,int begin, int end)
{
    int pivot = A[end];
    int lEnd = begin -1, rEnd = begin;
    
    for(; rEnd<end; rEnd++)
    {
        if(A[rEnd] < pivot)
        {
            lEnd += 1;
            swap(A[lEnd],A[rEnd]);
        }
    }
    swap(A[lEnd+1], A[end]);
   
    return lEnd+1;
}

void quickSort(int *A, int begin, int end)
{
    if(begin >= end)
        return;
    int q = partition(A, begin, end);
    quickSort(A,begin,q-1);
    quickSort(A, q+1, end);
}
int main()
{
    int a[] = {5, 13, 2, 25, 7, 17, 20, 8, 4, 1, 2, 3, 4, 7, 8, 9, 10, 14, 16};
    quickSort(a,0,18);
    for(auto i : a)
    {
        cout<<i<<" ";
    }
    return 0;

}