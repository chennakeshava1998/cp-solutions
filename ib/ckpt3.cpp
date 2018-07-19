// https://www.interviewbit.com/problems/numrange/

#include <bits/stdc++.h>
using namespace std;

int numRange(vector<int> &A, int B, int C)
{
    vector<int> prefix(A.size());
    prefix[0] = A[0];

    for (int i = 1; i < A.size(); ++i)
        prefix[i] = prefix[i - 1] + A[i];

    int ans = 0, k = 0;

    while (1)
    {
        auto p = lower_bound(prefix.begin() + k, prefix.end(), B);
        auto q = lower_bound(prefix.begin() + k, prefix.end(), C);

        if ((*p > C) || (p == q && q == prefix.end()))
            break;

        ans += (q - p);
        B -= (*p);
        C -= (*p);
        cout << p - prefix.begin() << "\t" << q - prefix.begin() << endl;

        k = q - prefix.begin();
    }

    return ans;
}

int main()
{
    vector<int> A = {10, 5, 1, 0, 2};
    int B = 6, C = 8;

    cout << numRange(A, B, C) << endl;

    return 0;
}