#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

vector<int> v;
void update(int, int);
int sum(int, int);
void update(int l, int r)
{
    int i = l;
    for (; i <= r; ++i)
        v[i] += (i - l + 1) * (i - l + 1);
}

int sum(int l, int r)
{
    int sum = 0;
    for (int i = l; i <= r; ++i)
        sum += v[i];

    return sum % (int)(pow(10, 9) + 7);
}

int main()
{
    int n, q, x, l, r;

    cin >> n >> q;
    v.resize(n, 0);

    while (q--)
    {
        cin >> x >> l >> r;
        if (x == 1)
            update(l, r);
        else
            cout << sum(l, r) << endl;
    }

    return 0;
}