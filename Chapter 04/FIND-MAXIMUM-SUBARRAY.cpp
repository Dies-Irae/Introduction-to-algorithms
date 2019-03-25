//找出和最大的子序列
#include<iostream>
#include<assert.h>
using namespace std;

struct answer{
    int sum;
    int *left;
    int *right;
    answer(): sum(0), left(nullptr), right(nullptr) {}
    answer(int *mid) : sum(*mid),left(mid),right(mid) {}
};

answer findMaxSubarrayCrossMid(int *left, int *right, int *mid)
{
    int tmpSum = 0, rightSum = *mid;
    answer ans(mid);

    for(auto tmpLeft=mid; tmpLeft>left; tmpLeft--)
    {
        tmpSum += *tmpLeft;
        if(tmpSum > ans.sum)
        {
            ans.left = tmpLeft;
            ans.sum = tmpSum;
        }
    }
    tmpSum = 0;
    for(auto tmpRight=mid+1; tmpRight<right; tmpRight++)
    {
        tmpSum += *tmpRight;
        if(tmpSum > rightSum)
        {
            ans.right = tmpRight;
            rightSum = tmpSum;
        }
    }
    ans.sum += rightSum;
    return ans;

}


answer findMaxSubarray(int *left, int *right)
{
    if(right <= left)
        return answer(left);
    else
    {
        answer leftAns, rightAns, midAns;
        int *mid = left + (right-left)/2;

        leftAns = findMaxSubarray(left, mid);
        rightAns = findMaxSubarray(mid+1, right);
        midAns = findMaxSubarrayCrossMid(left, right, mid);
        if(leftAns.sum > rightAns.sum)
        {
            if(leftAns.sum >midAns.sum)
                return leftAns;
            else
                return midAns;
        }
        else
        {
            if(rightAns.sum >midAns.sum)
                return rightAns;
            else
                return midAns;
        }
    }
}

int main()
{
    answer ans;
    int a[] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7} ;
    //int b[] ={-2,-3,-56,-1,-76,-4}; 若输入均为负数，则返回最大的一个负数

    ans = findMaxSubarray(a,&a[15]);
    cout << "Max Sum :" <<ans.sum<<endl; 
    cout << "Left Bound :" << ans.left-a <<endl; 
    cout << "Right Bound :" << ans.right -a <<endl; 

}