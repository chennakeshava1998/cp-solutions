/*
*Problem 1:* Given an array A of n integers, find 3 integers in S such that the sum is closest to a given number.
Print the sum of the three integers. (You may print any valid solution if multiple exist)

Example:
A = {-1 2 1 -4},
Given number = 1.
The sum that is closest to the given number is 2. (-1 + 2 + 1 = 2)
*/

// Algorithm: https://stackoverflow.com/questions/2070359/finding-three-elements-in-an-array-whose-sum-is-closest-to-a-given-number

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

int closestSum(vector<int> v, int target);

int main()
{
    int n, x, target;
    cin >> n; // number of integers in the array

    vector<int> v;
    while (n--)
    {
        cin >> x;
        v.pb(x);
    }

    cin >> target;

    cout << closestSum(v, target) << endl;

    return 0;
}

int closestSum(vector<int> v, int target)
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
            if (abs(temp - target) < abs(curr_sum - target))
                curr_sum = temp;

            if (temp == target)
                return temp;

            if (temp < target)
                ++start;
            else
                --end;
        }
    }

    return curr_sum;
}
