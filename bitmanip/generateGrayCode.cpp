#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, tmp;
    cin >> n;

    for (int i = 0; i < (1 << n); ++i)
        cout << (i ^ (i >> 1)) << endl;

    return 0;
}