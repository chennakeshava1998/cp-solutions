#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, y, i, sum = 0;
    cin >> n >> x >> y;
    vector<int> v;
    vector<int> split(n, 2);
    while (n--)
    {
        cin >> i;
        sum += i;
        v.push_back(i);
    }

    if (sum % (__gcd(x, y)) == 0)
    {
        cout << "Yes\n";
        set<int> a, b;
        for (i = 0; i < v.size(); ++i)
        {

            if (binary_search(v.begin(), v.end(), x - v[i]))
            {
                a.insert(v[i]);
                a.insert(x - v[i]);
                v[i] = 0;
                auto p = lower_bound(v.begin(), v.end(), x - v[i]);
                *p = 0;
                split[i] = 0;
                split[p - v.begin()] = 0;
            }
            else if (a.find(x - v[i]) != a.end()) // conjugate-element is already present in the set-A
            {
                a.insert(v[i]);
                split[i] = 0;
                v[i] = 0;
            }
            else //element must belong to set-B
            {
                b.insert(v[i]);
                v[i] = 0;
                split[i] = 1;
            }
        }

        for (auto u : split)
            cout << u << " ";
        cout << endl;
    }
    else
        cout << "No\n";
}