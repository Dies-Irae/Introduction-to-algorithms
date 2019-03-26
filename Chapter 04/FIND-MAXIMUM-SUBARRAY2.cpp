/*A nonrecursive, linear-time algorithm for the
maximum-subarray problem. From 4.1-5*/
#include<iostream>
using namespace std;
struct answer{
    int sum;
    int *left;
    int *right;
    answer(): sum(0), left(nullptr), right(nullptr) {}
    answer(int *mid) : sum(*mid),left(mid),right(mid) {}
};

answer findMaxSubarray(int *left, int *right)//查找两端都是闭区间
{
    answer ans(left), ans2(left);
    for(auto rear=left+1; rear<right; rear++)
    {
        if(ans2.sum > 0)
        {
            ans2.sum += *rear;
            ans2.right = rear;
        }
        else
        {
            ans2.sum = *rear;
            ans2.left = rear;
            ans2.right = rear;
        }
        if(ans2.sum> ans.sum)
        {
            ans.right = ans2.right;
            ans.sum = ans2.sum;
            ans.left = ans2.left; 
        }
    }
    return ans;
}
int main()
{
    answer ans;
    int a[] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7} ;

    ans = findMaxSubarray(a,&a[15]);
    cout << "Max Sum :" <<ans.sum<<endl; 
    cout << "Left Bound :" << ans.left-a <<endl; 
    cout << "Right Bound :" << ans.right -a <<endl; 

}