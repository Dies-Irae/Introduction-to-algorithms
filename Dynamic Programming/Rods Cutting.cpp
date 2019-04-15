#include<iostream>
#include <map>
#include <vector>


using namespace std;

int priceTable[10] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
map<int, int> memDict;
vector<int> memVect = {0};

int cutRod(int length)
{
    if(length == 0)
        return 0;
    int revenue = 0;
    int tmp;
    for(int i=1; i<=10 && i<=length; i++)
    {
        tmp = cutRod(length-i)+priceTable[i-1];
        revenue = revenue>tmp ? revenue:tmp;
    }
    return revenue;
}

int cutRodTopDown(int length)
{
    if(length == 0)
        return 0;
    auto dictIter = memDict.begin();
    dictIter = memDict.find(length);
    if(dictIter != memDict.end())
        return dictIter->second;
    int revenue = 0;
    int tmp;
    for(int i=1; i<=10 && i<=length; i++)
    {
            tmp = cutRodTopDown(length-i)+priceTable[i-1];
            revenue = revenue>tmp ? revenue:tmp;
    }
    memDict.insert({length,revenue});
    return revenue;
}
int cutRodBottomUp(int length)
{
    int revenue;
    int tmp;
    for(int i=1; i<=length; i++)
    {
        revenue = 0;
        for(int j=0; j<i && j<10; j++)
        {
            tmp = priceTable[j]+memVect[i-j-1];
            revenue = revenue>tmp ? revenue:tmp;
        }
        memVect.push_back(revenue);
    }
    return memVect[length];
}
int main()
{
    cout<<cutRod(27)<<endl;
    cout<<cutRodTopDown(27)<<endl;
    cout<<cutRodBottomUp(27)<<endl;

}
