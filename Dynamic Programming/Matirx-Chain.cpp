#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int matrixChain[] = { 30, 35, 15, 5, 10, 20, 25 };
int cost[6][6];
int s[6][6];
int findMinCost(int i, int j)
{
	vector<int> tmp;
	for (int k = i; k<j; k++)
	{
		tmp.push_back(cost[i][k] + cost[k + 1][j] + matrixChain[i] * matrixChain[k + 1] * matrixChain[j + 1]);
	}
	auto minIter = min_element(tmp.begin(), tmp.end());
	s[i][j] = minIter - tmp.cbegin() + i;
	return *minIter;
}
int matirxChainCost()
{
	for (int i = 0; i<6; i++)
	{
		for (int j = i; j<6; j++)
		{
			if (j - i == j)
				cost[j - i][j] = 0;
			else
				cost[j - i][j] = findMinCost(j - i, j);
		}
	}
	return cost[0][5];
}

void printAns(int i, int j)
{
	if (i == j)
		cout << 'A' << i;
	else
	{
		cout << '(';
		printAns(i, s[i][j]);
		printAns(s[i][j]+1, j);
		cout << ')';
	}


}

int main()
{
	cout << matirxChainCost() << endl;
	printAns(0, 5);
}