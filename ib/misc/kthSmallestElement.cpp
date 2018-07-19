// https://practice.geeksforgeeks.org/problems/kth-smallest-element/0
#include <bits/stdc++.h>
using namespace std;

int kthSmallestElem(vector<int> v, int k);
int kthSmallestElem(vector<int> v, int k)
{
    // this idea of boolean array does not work if there are multiple elements. The boolean value can capture only the presence or absence of an element. It cannot contain information on the frequency of elements.
    vector<bool> a(*max_element(v.begin(), v.end()) + 1, 0);
    int i;
    for (i = 0; i < v.size(); ++i)
        a[v[i]] = 1;

    i = 0;
    int cnt = 0;
    while (cnt < k && i < a.size())
    {
        if (a[i] == 1)
            ++cnt;

        ++i;
    }

    // i would have been incremented already, even after cnt becomes equal top k.
    return (i - 1);
}

int main()
{
    int t, n, k, x;
    // cout << "No. of test cases:\n";
    cin >> t;
    while (t--)
    {
        // cout << "No. of elements:\n";
        cin >> n;
        vector<int> v;
        while (n--)
        {
            cin >> x;
            v.push_back(x);
        }
        // cout << "Which element:\n";
        cin >> k;

        cout << kthSmallestElem(v, k) << endl;
    }

    return 0;
}