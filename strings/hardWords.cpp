#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// vector<string> splitString(string s);
bool checkHard(string s);
bool checkHard(string s)
{
    int num_of_consonants = 0, cont_cons_cnt = 0;

    for (int i = 0; i < s.size(); ++i)
    {
        s[i] = tolower(s[i]);
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            cont_cons_cnt = 0;
            continue;
        }
        else
        {
            ++num_of_consonants;
            ++cont_cons_cnt;
        }

        if (cont_cons_cnt == 4)
            return 1;
    }

    if (num_of_consonants > (s.size() / 2))
        return 1;

    return 0;
}

int findHardness(vector<string> v)
{
    int hard = 0, easy = 0, cost = 0;

    for (int i = 0; i < v.size(); ++i)
    {
        if (checkHard(v[i]))
            ++hard;
        else
            ++easy;
    }

    cost = hard * 5 + easy * 3;
    return cost;
}

int main()
{
    vector<string> v = {"abcd", "of", "eee"};
    cout << findHardness(v) << endl;

    return 0;
}