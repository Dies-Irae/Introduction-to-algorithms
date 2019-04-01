#include <iostream>
#include<random>
using namespace std;

int partition(int *A,int begin, int end)
{
    int key = A[begin];
    int i = begin - 1;
    int j = end + 1;  
    while(true)
    {
        do{
            j -= 1;
        }while(A[j] > key);
        do{
            i += 1;
        }while(A[i] < key);
        if(i < j)
            swap(A[i],A[j]);
        else
            return j;
    }
}

int randomPartition(int *A,int begin, int end)
{
    static default_random_engine rng;
    uniform_int_distribution<unsigned> uni(begin, end);
    swap(A[uni(rng)],A[begin]);
    return partition(A, begin, end);
    
}

void quickSort(int *A, int begin, int end)
{
    if(begin >= end)
        return;
    int q = randomPartition(A, begin, end);
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