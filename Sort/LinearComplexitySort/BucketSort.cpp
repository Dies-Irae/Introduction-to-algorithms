#include<iostream>
#include<forward_list>
using namespace std;
void bucketSort(double src[], int srcLen, double dest[])
{
    double *dptr = dest;
    forward_list<double> buckets[10];
    for(int i=0; i<srcLen; i++)
    {
        buckets[int(src[i]*10)].push_front(src[i]);
    }
    for(int i=0; i<10; i++)
    {
        buckets[i].sort();
    }
    for(int i=0; i<srcLen; i++)
    {
        while(buckets[i].empty() != true)
        {
            *dptr = buckets[i].front();
            buckets[i].pop_front();
            dptr++;
        }
    }
}
int main()
{
    double a[] = {.79, .13, .16, .64, .39, .20, .89, .53, .71, .42};
    double b[10];
    bucketSort(a,10,b);
    for(auto i : b)
    {
        cout<<i<<" ";
    }
    return 0;
}