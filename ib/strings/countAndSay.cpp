// https://www.interviewbit.com/problems/count-and-say/
#include <sstream>
vector<int> func(vector<int>);
string vec2string(vector<int>);
vector<int> func(vector<int> v)
{
    int i, j;
    vector<int> ans;

    for (i = 0; i < v.size(); ++i)
    {
        j = i;
        while ((j < v.size() - 1) && (v[j] == v[j + 1]))
            ++j;

        ans.push_back(j - i + 1);
        ans.push_back(v[j]);
        i = j;
    }

    return ans;
}

string vec2string(vector<int> v)
{
    stringstream ss;
    for (int i = 0; i < v.size(); ++i)
        ss << v[i];

    string s = ss.str();
    return s;
}

string Solution::countAndSay(int A)
{
    vector<int> ans, v;
    v.push_back(1);

    string s;

    if (A <= 0)
        return s;

    if (A == 1)
        return vec2string(v);

    int i;
    for (i = 1; i < A; ++i)
    {
        ans.clear();
        ans = func(v);
        v.clear();
        v = ans;
    }

    return vec2string(ans);
}
