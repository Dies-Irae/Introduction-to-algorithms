#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int lcs[6][7];
void LCS_Length(string x, string y)
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (x[i] == y[j])
            {
                if (i > 0 && j > 0)
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                else
                    lcs[i][j] = 1;
            }
            else
            {
                if (i == 0 && j == 0)
                    lcs[i][j] = 0;
                else if (i == 0)
                    lcs[i][j] = lcs[i][j - 1];
                else if (j == 0)
                    lcs[i][j] = lcs[i - 1][j];
                else
                    lcs[i][j] = max({lcs[i - 1][j], lcs[i][j - 1]});
            }
        }
    }
}
char LCS_Print(int i, int j, string x, string y)
{
    if (i == 0 || j == 0)
    {
        return x[i];
    }
    else
    {
        if (x[i] == y[j])
        {
            cout << LCS_Print(i - 1, j - 1, x, y) << " ";
            return x[i];
        }
        else
        {
            if (lcs[i - 1][j] > lcs[i][j - 1])
                cout<< LCS_Print(i - 1, j, x, y);
            else
                cout<< LCS_Print(i, j - 1, x, y);
            return '\0';
        }
    }
}
int main()
{
    LCS_Length("BDCABA", "ABCBDAB");
    LCS_Print(5, 6, "BDCABA", "ABCBDAB");
}