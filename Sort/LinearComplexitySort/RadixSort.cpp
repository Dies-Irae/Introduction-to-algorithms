#include <iostream>
#include <string>
#include <queue>
using namespace std;
int countingSort2(string A[], int len, int digit, string *ans)
{
    string *ptr = &ans[0];
    queue<string *> tmp[25];
    for(int i=0; i<len; i++)
    {
        tmp[A[i][digit]-'A'].push(&A[i]);
    }
    for(int i=0; i<=25; i++)
    {
        while(tmp[i].size()>0)
        {
            *ptr = *(tmp[i].front());
            tmp[i].pop();
            ptr++;
        }
    }

}
int main()
{
    string A[] = {"COW", "DOG", "SEA", "RUG", "ROW", "MOB", "BOX", "TAB",
"BAR", "EAR", "TAR", "DIG", "BIG", "TEA", "NOW", "FOX"};
    string b[16];
    for(int i=2; i>=0; i--)
        countingSort2(A,16,i,b);
    for(auto i : b)
    {
        cout<<i<<" ";
    }
    return 0;
}