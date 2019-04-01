#include <iostream>
using namespace std;
void countingSort(int A[],int len, int range, int *ans)
{
    //range is [0,range]
    int *tmp = new int[range+1]();//initialize all entries in tmp with 0
    int *ptr = ans;
    for(int i=0; i<len; i++)
    {
        tmp[A[i]] += 1;
    }
    for(int i=0; i<=range; i++)
    {
        while(tmp[i]>0)
        {
            *ptr = &tmp[i]-tmp;
            tmp[i] -= 1;
            ptr++;
        }
    }
}
int main()
{
    int a[] = {6, 0, 2, 0, 1, 3, 4, 6, 1, 3, 2};
    int b[11];
    countingSort(a,11,6,b);
    for(auto i : b)
    {
        cout<<i<<" ";
    }
    return 0;
}