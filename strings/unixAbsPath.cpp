#include <bits/stdc++.h>
using namespace std;

string SimplePath(vector<string>);
vector<string> splitString(string);

vector<string> splitString(string s)
{
    vector<string> v;
    string temp;
    for (int i = 0; i < s.size(); ++i)
    {
        /*
            if (s[i] == '/')
            {
                if (temp != "." && !temp.empty())
                    v.push_back(temp);
                temp.clear();
                continue;
            }
            int j = i;
            while (s[j] != '/')
            {
                temp += s[j];
                ++j;
            }
            i = j - 1;
        */

        if (s[i] == '/')
            continue;

        int j = i;
        while (s[j] != '/' && j < s.size())
        {
            temp += s[j];
            ++j;
        }

        if (temp != "." && !temp.empty())
        {
            v.push_back(temp);
            temp.clear();
        }
        else if (temp == ".")
            temp.clear();
        i = j;
    }

    return v;
}
string SimplePath(vector<string> v)
{
    string s;
    stack<string> st;

    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] == "..")
        {
            if (!st.empty())
                st.pop();
            else
            {
                cout << "Invalid Path\n";
                return s;
            }
        }
        else
            st.push(v[i]);
    }

    stack<string> supplementary;

    while (!st.empty())
    {
        supplementary.push(st.top());
        st.pop();
    }

    while (!supplementary.empty())
    {
        s += "/";
        s += supplementary.top();
        supplementary.pop();
    }
    return s;
}

int main()
{
    string s;
    cin >> s;

    vector<string> v = splitString(s);
    cout << SimplePath(v) << endl;

    return 0;
}