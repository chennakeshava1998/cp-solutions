#include <bits/stdc++.h>
#include <sstream> // header file used for stringstream
using namespace std;

string vec2string(vector<int>);
string vec2string(vector<int> v)
{
    stringstream ss;
    for (int i = 0; i < v.size(); ++i)
        ss << v[i];

    string s = ss.str();
    return s;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, -7, -8};
    cout << vec2string(v) << endl;

    return 0;
}
