#include <bits/stdc++.h>
using namespace std;

int func(vector<int> v);
vector<int> row_flip(vector<int> v, int i);
vector<int> col_flip(vector<int> v, int i);
vector<int> v;
int m, n;
int sum, num_iter;
int func(vector<int> v)
{
    // completed all p&c
    if (num_iter == (1 << (m + n)))
        return 0;

    

    
}

vector<int> row_flip(vector<int> v, int i);
{
    vector<int> A;
    A[i] = (1 << n) - 1 - v[i];

    return A;
}

vector<int> col_flip(vector<int> v, int i);
{
    vector<int> A;

    for (auto i = 0; i < m; ++i)
    {
        A[i] = (1 << j) ^ v[i];
    }

    return A;
}

int main()
{
    int t, x, sum = -1, num_iter = 0;

    cin >> t;
    while (t--)
    {
        cin >> m >> n;
        v.resize(m, 0);

        for (auto i = 0; i < m; ++i)
        {
            for (auto j = n - 1; j >= 0; --j)
            {
                cin >> x;
                // cout << x << " ";
                if (x)
                    v[i] += (1 << j);
            }
            // cout << endl;
        }

        cout << func() << endl;
    }

    return 0;
}
