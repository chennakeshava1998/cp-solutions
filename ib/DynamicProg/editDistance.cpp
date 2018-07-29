#include <bits/stdc++.h>
#include <string>
using namespace std;

// vector<vector<int>> dp;
void disp(vector<vector<int>> dp, string A, string B)
{
    cout << "Disp function:\n\n";
    cout << "  ";
    for (int j = 0; j < dp[0].size(); ++j)
        cout << B[j] << "  ";
    cout << endl;

    for (int i = 0; i < dp.size(); ++i)
    {
        cout << A[i] << " ";
        for (int j = 0; j < dp[0].size(); ++j)
            cout << dp[i][j] << " ";
        cout << endl;
    }

    cout << "End of disp function\n\n";
}

int func(int i, int j, string A, string B, vector<vector<int>> dp)
{
    string a, b;
    if (i >= A.size())
        a = "";
    else
        a = A.substr(i);

    if (j >= B.size())
        b = "";
    else
        b = B.substr(j);

    if (a == "" && b == "")
        return 0;
    if (a == "" || b == "")
    {
        if (!a.empty())
            return a.size();
        else
            return b.size();
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    // if the first characters are identical
    if (a[0] == b[0])
    {
        return (dp[i][j] = func(i + 1, j + 1, A, B, dp));
    }

    int insert_cost = func(i, j + 1, A, B, dp);
    int rep_cost = func(i + 1, j + 1, A, B, dp);
    int del_cost = func(i + 1, j, A, B, dp);

    return (dp[i][j] = 1 + min(insert_cost, min(del_cost, rep_cost)));
}

int wrapperFunc(string p, string q)
{
    vector<vector<int>> dp(p.size(), vector<int>(q.size(), -1));

    return func(0, 0, p, q, dp);
    // cout << func(0, 0, p, q, dp) << endl;
    // disp(dp, p, q);
}

int Solution::minDistance(string A, string B)
{
    return wrapperFunc(A, B);
}
int main()
{

    return 0;
}