// https://www.interviewbit.com/problems/jump-game-array/
#include <bits/stdc++.h>
using namespace std;

/* O(n^2) time, linear space;
bool reachable(vector<int> v)
{
    vector<bool> reachable(v.size(), 0);
    int n = v.size();
    reachable[n - 1] = 1;

    for (int i = n - 2; i >= 0; --i)
    {
        int j = i + 1;
        while (j < reachable.size() && (j <= (i + v[i])))
        {
            if (reachable[j])
            {
                reachable[i] = 1;
                break;
            }
            ++j;
        }
    }

    return reachable[0];
}
*/

/* Linear Time, linear space
bool reachable(vector<int> v)
{
    int n = v.size();
    vector<bool> ans(n, 0);
    vector<int> sum(n + 1, 0);

    ans[n - 1] = 1;
    sum[n - 1] = 1;
    sum[n] = 0;

    for (int i = n - 2; i >= 0; --i)
    {
        int high = min(n - 1, i + v[i]);
        int temp_sum = sum[i + 1] - sum[high + 1];

        if (temp_sum > 0)
            ans[i] = 1;

        sum[i] = ans[i] + sum[i + 1];
    }

    return ans[0];
}
*/

// Linear Time, constant space
bool reachable(vector<int> v)
{
    int n = v.size();
    int minPossible = n - 1;

    for (int i = n - 2; i >= 0; --i)
    {
        bool isPossibleFromThisIndex = 0;
        if ((i + v[i]) >= minPossible)
        {
            minPossible = i;
            isPossibleFromThisIndex = 1;
        }

        if (i == 0)
            return isPossibleFromThisIndex;
    }
}

int main()
{
    int n, x;
    vector<int> v;
    while (n--)
    {
        cin >> x;
        v.push_back(x);
    }

    cout << reachable(v) << endl;

    return 0;
}