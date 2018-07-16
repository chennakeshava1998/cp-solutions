#include <iostream>
#include <cmath>
using namespace std;
#define MOD ((int)pow(10, 9) + 7)

long long int nchoosek(long long int n, long long int k)
{
    if (n < k)
        return 0;

    if (k == 0 || (n == k))
        return 1;

    if (k > (n - k))
        k = n - k;

    long long int ans = 1;
    for (long long int i = 1; i <= k; ++i)
    {
        ans = ((ans % MOD) * (n - i + 1) % MOD) % MOD;
        ans %= MOD;
        ans /= i;
    }

    return (ans % MOD);
}

int main()
{
    int t, n, r;
    cin >> t;
    while (t--)
    {
        cin >> n >> r;
        cout << nchoosek(n, r) << "\n";
    }

    return 0;
}