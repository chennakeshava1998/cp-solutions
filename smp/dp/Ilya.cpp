// http://codeforces.com/problemset/problem/518/D
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

vector<vector<double>> dp(2001, vector<double>(2001, -1));
double p;
double solve(int n, int t);

int main()
{
    int n, t;
    cin >> n >> p >> t;

    cout << setprecision(10);
    cout << solve(n, t) << endl;

    return 0;
}

double solve(int n, int t)
{
    if (!n || !t)
        return 0;

    if (dp[n][t] != -1)
        return dp[n][t];

    double ans = p * (solve(n - 1, t - 1) + 1) + (1 - p) * solve(n, t - 1);

    return dp[n][t] = ans;
}
