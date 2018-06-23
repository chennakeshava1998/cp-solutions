#include <bits/stdc++.h>
using namespace std;

int func();
void row_flip(int i);
void col_flip(int i);
vector<int> v;
int m, n;

int main()
{
    int t, x;

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

int func()
{
    int i, j;
    vector<int> num_ones(n, 0); // number of ones in each columns
    bool flag = 1;

    while (flag)
    {
        flag = 0;
        // pre-processing after row-transforms, not before!!
        for (i = 0; i < m; ++i)
        {
            for (j = 0; j < n; ++j)
            {
                if (v[i] & (1 << j))
                    num_ones[j]++;
            }
        }

        // col_transforms
        for (j = 0; j < n; ++j)
        {
            if (num_ones[j] < n / 2)
            {
                col_flip(j);
                flag = 1;
            }
        }

        // row transforms:
        for (i = 0; i < m; ++i)
        {
            if (v[i] < (1 << (n - 1))) // msb is zero, hence flip
            {
                row_flip(i);
                flag = 1;
            }
        }
    }

    return accumulate(v.begin(), v.end(), 0);
}

void row_flip(int i)
{
    v[i] = (1 << n) - 1 - v[i];
}

void col_flip(int j)
{
    for (auto i = 0; i < m; ++i)
    {
        v[i] = (1 << j) ^ v[i];
    }
}