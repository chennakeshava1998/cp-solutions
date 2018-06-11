/*
Problem 2 (Optional, but recommended):
 Given an unsorted integer array, find the first missing positive integer.
Example:
Given [1,2,0] return 3,
[3,4,-1,1] return 2,
[-8, -7, -6] returns 1.
*/
// TODO: Optimise space. For Input: -2 10000, this program takes a lot of space.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, i;
    cin >> n; // number of integers
    vector<int> v;
    while (n--)
    {
        cin >> x;
        v.push_back(x);
    }

    vector<bool> ans(*max_element(v.begin(), v.end()) + 1, 0);

    for (i = 0; i < v.size(); ++i)
    {
        if (v[i] <= 0)
            continue;

        ans[v[i]] = 1;
    }
    int final_ans = -1;
    for (i = 1; i < ans.size(); ++i)
    {
        if (ans[i] == 0)
        {
            final_ans = i;
            break;
        }
    }

    if (final_ans != -1)
        cout << final_ans << endl;
    else
        cout << ans.size() << endl;

    return 0;
}