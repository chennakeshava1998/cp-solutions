#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return 0;

    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

int func(vector<int> &A, int B)
{
    int cnt = 0;
    for (int i = 0; i < A.size(); ++i)
    {
        if (isPrime(A[i]) && (B % A[i]) == 0)
            ++cnt;
    }

    return cnt;
}

int main()
{
    vector<int>A = {1, 2, 3, 4, 5};
    int B = 6;
    cout << func(A, B) << endl;
    return 0;
}