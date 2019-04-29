#include<iostream>
#include<vector>

using namespace std;
int timeTable[11][2] = { { 1,4 },{ 3,5 },{ 0,6 },{ 5,7 },{ 3,9 },{ 5,9 },{ 6,10 },{ 8,11 },{ 8,12 },{ 2,14 },{ 12,16 } };
vector<int> ans;
void recursiveActivitySelector(int lastSelected, int questionSize)
{
	int q = lastSelected + 1;
	while (q < questionSize && timeTable[lastSelected][1] > timeTable[q][0])
	{
		++q;
	}
	if (q <= questionSize)
	{
		ans.push_back(q);
		recursiveActivitySelector(q, questionSize);
	}
	else
		return;

}
int main()
{
	recursiveActivitySelector(-1, 10);
	for (auto i : ans)
	{
		cout << i << " ";
	}
}