// https://www.geeksforgeeks.org/minimum-number-jumps-reach-endset-2on-solution/
// O(n) solution

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long

ll calcMinJumps(vector<ll> v);

int main()
{
    ll t, n, x;
    cin >> t;

    while (t--)
    {
        cin >> n;
        vector<ll> v;
        while (n--)
        {
            cin >> x;
            v.pb(x);
        }

        cout << calcMinJumps(v) << "\n";
    }
    return 0;
}

ll calcMinJumps(vector<ll> v)
{
    ll maxCurrRange = v[0]; // This is max index of the array, that can be currently reached.

    ll steps = v[0]; // The remaining successive cells that can be explored.

    ll jumps = 1; // The min number of jumps required to reach the last position.

    // Although we have the check condition on i >= maxCurrRange, it is checked only when steps=0 && maxCurrRange value will change in the index i=1 to v[1] + 1. Hence, we need this condition before the loop traversal.
    // v[0] = 0, implies we can't move to any further cell 
    if(v[0] == 0)
        return -1;

    for (int i = 1; i < v.size(); ++i)
    {
        // Without the below stmt, if steps become 0 at exactly index n-1, then the number of jumps will be incremented by 1. But, the required answer is only until reaching the last position.
        if (i == v.size() - 1)
            return jumps;

        maxCurrRange = max(maxCurrRange, i + v[i]);
        --steps;

        if (steps == 0)
        {
            // Since the number of remaining steps have become 0, we must have jumped somewhere in between.
            ++jumps;

            // Possible Input Sequence: 2 0 0 0 4; After reaching the second 0, we will have hit the maxCurrRange. Hence, we won't be able to continue to explore further.
            if (i >= maxCurrRange)
                return -1;

            steps = maxCurrRange - i; // These cells can be explored without neccesarily taking a jump.
        }
    }

}
