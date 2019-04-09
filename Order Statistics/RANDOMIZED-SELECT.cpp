#include<iostream>
#include<random>
using namespace std;
int randomizedPartition(int A[], int begin, int end)
{
        static default_random_engine rng;
        uniform_int_distribution<unsigned> uni(begin,end);
        int rnd = uni(rng);
        swap(A[end],A[rnd]);
        int key = A[end];
        int lEnd = begin -1;
        int rEnd = begin;
        while(rEnd != end)
        {
            if(A[rEnd] < key)
            {
                lEnd ++;
                swap(A[rEnd],A[lEnd]);
            }
            rEnd ++;
        }
        swap(A[end],A[lEnd+1]);
        return lEnd+1;
}
int randomizedSelect(int A[], int begin, int end, int rank)
{
    if(begin == end)
        return A[begin];
    int mid = randomizedPartition(A,begin,end);
    int offset = mid - begin + 1;
    if(rank > offset)
        randomizedSelect(A,mid,end,rank-mid);
    else if(rank < offset)
        randomizedSelect(A,begin,mid,rank);
    else
        return A[mid];    

}
int main()
{
    int A[] = {3, 2, 9, 0, 7, 5, 4, 8, 6, 1};
    for(int i=1;i<=10;i++)
    {
        cout<<"NO."<<i<<" : "<<randomizedSelect(A,0,9,i)<<endl;
    }

}