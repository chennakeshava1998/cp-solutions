// https://www.interviewbit.com/problems/ways-to-form-max-heap/
#include <cmath>
#define MOD ((int)pow(10, 9) + 7)
long long int nchoosek(long long int n, long long int k);
long long int numMaxHeap(long long int n);

int Solution::solve(int n)
{
    if (n <= 2)
        return 1;

    long long int h = log2(n); // height of the tree
    // No. of nodes in the left and right subtree resp.
    long long int L, R;

    // No. of leaves left, at the last level of tree
    // The second term obtained by summing all nodes from first to the penultimate level.
    long long int p = n - ((1 << h) - 1);

    // Max number of leaves possible in the last level of tree
    long long int m = (1 << h);

    if (p >= m / 2) // Is left subtree full?
        L = (1 << h) - 1;
    else
        L = (1 << h) - 1 - (m / 2 - p);

    R = (n - 1) - L;

    long long int a = nchoosek(n - 1, L) % MOD;
    long long int b = solve(L) % MOD;
    long long int c = solve(R) % MOD;

    return (int)(((a * b) % MOD) * c) % MOD;
}

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

    return ans % MOD;
}