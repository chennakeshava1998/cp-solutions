
// https://www.geeksforgeeks.org/find-a-triplet-that-sum-to-a-given-value/

// Algorithm: https://stackoverflow.com/questions/2070359/finding-three-elements-in-an-array-whose-sum-is-closest-to-a-given-number

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

vector<tuple<int, int, int>> ans;

bool closestSum(vector<int> v, int target);

int main()
{
    int n, x, target, t;
    cin >> t; // Enter the number of test cases

    while (t--)
    {
        cin >> n; // number of integers in the array

        vector<int> v;
        while (n--)
        {
            cin >> x;
            v.pb(x);
        }

        target = 0;

        // cout << closestSum(v, target) << endl;
        bool useless_var = closestSum(v, target);
        // cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); ++i)
            cout << get<0>(ans[i]) << " " << get<1>(ans[i]) << " " << get<2>(ans[i]) << endl;
    }

    return 0;
}

bool closestSum(vector<int> v, int target)
{
    sort(all(v)); // O(NlogN)

    int i, start, end, curr_sum = 1e9, n = v.size();
    // curr_sum holds the currently closest value to the target
    for (i = 0; i < n - 2; ++i)
    {
        start = i + 1; // this pointer starts right after i
        end = n - 1;   // this pointer starts from the RHS end of the array

        while (start < end) // This loop takes atmost O(N) time
        {
            // There is no need to continue after the start and end pointers have crossed each other, because all such combinations have been previously reached.
            int temp = v[i] + v[start] + v[end];

            // The below two numbers are required for the closest sum variant of this problem
            // if (abs(temp - target) < abs(curr_sum - target))
            //     curr_sum = temp;

            if (temp == target)
            {
                ans.push_back(make_tuple(i, start, end));
                break;
            }
            if (temp < target)
                ++start;
            else
                --end;
        }
    }

    return 0;
}
