// https://www.interviewbit.com/problems/largest-number/

bool comp(const string &a, const string &b)
{
    string x = a + b, y = b + a;

    return x < y;
}

string Solution::largestNumber(const vector<int> &A)
{
    string ans;
    vector<string> v;
    int i = 0;

    for (; i < A.size(); ++i)
    {
        stringstream ss;
        ss << A[i];
        v.push_back(ss.str());
    }

    sort(v.rbegin(), v.rend(), comp);

    for (auto u : v)
        ans += u;

    // removing leading zeros in ans
    i = 0;
    // while (ans[i] != 0) ====> Comparison with a char is required. This stmt is true for all non-NULL characters.

    while (ans[i] == '0')
        ans.erase(i);

    if (ans.empty())
        ans += "0";

    return ans;
}
