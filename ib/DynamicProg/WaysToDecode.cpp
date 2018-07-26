// https://www.interviewbit.com/problems/ways-to-decode/
#include <bits/stdc++.h>
using namespace std;

map<string, int> m;

void buildMap()
{
    m["0"] = 0;
    m["10"] = 1;
    m["20"] = 1;

    for (int i = 1; i <= 26; ++i)
    {
        if (i == 10 || i == 20)
            continue;

        if (i < 10)
            m[to_string(i)] = 1;
        else
            m[to_string(i)] = 2;
    }
}

int func(string A)
{
    if (m.count(A))
        return m[A];

    if (A == "")
        return 0;

    if (A.size() == 2 && A[0] == '0')
        return 0;

    int lastButOne = 0, n = A.size(), secondLastButOne = 0;

    if (A[n - 1] != '0')
        lastButOne = func(A.substr(0, n - 1));

    if (A[n - 2] != '0' && stoi(A.substr(0, n - 2)) <= 26)
        secondLastButOne = func(A.substr(0, n - 2));

    m[A] = lastButOne + secondLastButOne;

    return m[A];
}