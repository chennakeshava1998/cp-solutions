// https://www.hackerearth.com/problem/algorithm/vaishu-and-tower-arrangements/description/

#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int minReplace(vector<int>);
int main()
{
    int t, n, x;

    cin >> t;
    while (t--)
    {
        cin >> n;
        // 1 and -1 are the inputs. Do not use a boolean vector
        vector<int> v;
        while (n--)
        {
            cin >> x;
            v.push_back(x);
        }

        cout << minReplace(v) << endl;
    }

    return 0;
}

int minReplace(vector<int> v)
{
    int cnt = 1e9, i, n = v.size(), total = 0, neg = 0;

    // total stores the total number of -1's in the vector
    for (i = 0; i < n; ++i)
    {
        if (v[i] == -1)
            total++;
    }

    // neg has the number of -1's encountered until index i
    // VERY IMP: Calculation at index-i places a boundary at (i + 1), so it is wrong to calculate at index i = n - 1. In that case, if a minimum actually occurs, then there might not be any "1" at the extreme RHS of the vector.
    for (i = 0; i < n - 1; ++i)
    {
        if (v[i] == -1)
            ++neg;
        // i - neg + 1 : number of 1's to the LHS of index-i, including i. That's why "+1" (indexing starts from 0).
        // total - neg: Number of -1's to the RHS of index-i, excluding i.
        cnt = min(cnt, i - neg + 1 + total - neg);
    }

    return cnt;
}
