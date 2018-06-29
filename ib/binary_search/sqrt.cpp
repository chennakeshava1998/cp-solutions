#include <bits/stdc++.h>
using namespace std;

int sqrt(int A)
{
    int low = 0, high = A, prev = 0;
    long long mid;
    for (auto i = 0; low <= high; ++i)
    {
        mid = low + (high - low) / 2;

        long long sq = mid * mid;

        if (sq == A)
            break;

        if (sq > A || mid >= (1 << 16) || mid <= -(1 << 16))
            high = mid - 1;
        else if (sq <= A)
        {
            low = mid + 1;
            prev = mid; // keep tracking of the last working mid
        }

        cout << mid << endl;
    }

    return low <= high ? mid : prev;
}

int main()
{
    cout << sqrt(2147483647) << endl;
    return 0;
}