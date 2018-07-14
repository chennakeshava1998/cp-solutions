// https://www.interviewbit.com/problems/largest-number/

bool comp(const string &a, const string &b)
{
    string A = a, B = b;
    if (A.size() == B.size())
        return A < B;

    if (A.size() < B.size())
        return B[A.size() - 1] < B[A.size()];
    else
        return A[B.size() - 1] < A[B.size()];
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

    return ans;
}
