// https://www.interviewbit.com/problems/longest-arithmetic-progression/
// hard, not completed yet 
#include <bits/stdc++.h>
using namespace std;

int findLongestAP(vector<int>, unordered_map<int, set<int>>);
unordered_map<int, set<int>> buildMap(vector<int>);
int findElem(int need, unordered_map<int, set<int>> m, int rhs_bound);

// test functions
void test_buildMap(vector<int> A);

unordered_map<int, set<int>> buildMap(vector<int> A)
{
    unordered_map<int, set<int>> ans;

    for (int i = 0; i < A.size(); ++i)
        ans[A[i]].insert(i);

    return ans;
}

void test_buildMap(vector<int> A)
{
    unordered_map<int, set<int>> ans = buildMap(A);

    // display the map
    for (auto it = ans.begin(); it != ans.end(); ++it)
    {
        cout << (it->first) << "\t";
        for (auto ptr = (it->second).begin(); ptr != (it->second).end(); ++ptr)
            cout << *ptr << " ";
        cout << endl;
    }
}

int findElem(int need, unordered_map<int, set<int>> m, int rhs_bound)
{
    if (!m.count(need))
        return -1;

    int pos;
    auto it = lower_bound(m[need].begin(), m[need].end(), rhs_bound);

    while (*it >= rhs_bound && it != m[need].rend())
        --it;

    if (it == m[need].rend())
        return -1;
    else
        return *it;
}

int main()
{
    vector<int>A = {9, 4, 7, 2, 10};
    test_buildMap(A);

    return 0;
}