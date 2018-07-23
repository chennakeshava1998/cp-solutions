// TODO: NlogN solution? : https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/

#include <bits/stdc++.h>
using namespace std;

int findLIS(vector<int>);

int findLIS(vector<int> v)
{
    vector<int> ans(v.size());

    for (int i = 0; i < v.size(); ++i)
    {
        int j = i - 1, cnt = 0;
        while (j >= 0)
        {
            if (v[j] < v[i])
                cnt = max(cnt, ans[j]);
            --j;
        }

        ans[i] = cnt + 1;
    }

    return *max_element(ans.begin(), ans.end());
}

int main()
{
    vector<int> v = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    cout << findLIS(v) << endl;

    return 0;
}