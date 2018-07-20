// https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/monk-at-the-graph-factory/

#include <bits/stdc++.h>
using namespace std;

void checkTree(vector<int> deg);

void checkTree(vector<int> deg)
{
    long long n = deg.size(), sum = accumulate(deg.begin(), deg.end(), 0);

    if (sum & 1)
        cout << "No\n";
    else if (sum != (2 * n - 2))
        cout << "No\n";
    else
        cout << "Yes\n";
}

int main()
{
    vector<int> deg;
    long long n, x;
    cin >> n;
    while (n--)
    {
        cin >> x;
        deg.push_back(x);
    }

    checkTree(deg);
    return 0;
}