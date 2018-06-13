#include <bits/stdc++.h>
using namespace std;

/*
Not sure how to use enum. This can eliminate the ugly if-else construct in the last loop.

enum roman_nums
{
    I = 1,
    V = 5,
    X = 10,
    L = 50,
    C = 100,
    D = 500,
    M = 1000
};
*/
int main()
{
    string roman;
    cin >> roman;
    int sum = 0, i;

    for (i = 0; i < roman.size() - 1; ++i)
    {
        if (roman[i] == 'I' && roman[i + 1] == 'V')
        {
            sum += 4;
            roman[i] = '-';
            roman[i + 1] = '-';
        }

        if (roman[i] == 'I' && roman[i + 1] == 'X')
        {
            sum += 9;
            roman[i] = '-';
            roman[i + 1] = '-';
        }
        if (roman[i] == 'X' && roman[i + 1] == 'C')
        {
            sum += 90;
            roman[i] = '-';
            roman[i + 1] = '-';
        }

        if (roman[i] == 'C' && roman[i + 1] == 'D')
        {
            sum += 400;
            roman[i] = '-';
            roman[i + 1] = '-';
        }

        if (roman[i] == 'C' && roman[i + 1] == 'M')
        {
            sum += 900;
            roman[i] = '-';
            roman[i + 1] = '-';
        }

        if (roman[i] == 'X' && roman[i + 1] == 'L')
        {
            sum += 40;
            roman[i] = '-';
            roman[i + 1] = '-';
        }
    }

    for (i = 0; i < roman.size(); ++i)
    {
        if (roman[i] == '-')
            continue;

        // cout << roman[i] << endl;
        if (roman[i] == 'I')
            sum += 1;
        if (roman[i] == 'V')
            sum += 5;
        if (roman[i] == 'X')
            sum += 10;
        if (roman[i] == 'L')
            sum += 50;
        if (roman[i] == 'C')
            sum += 100;
        if (roman[i] == 'D')
            sum += 500;
        if (roman[i] == 'M')
            sum += 1000;
    }

    cout << sum << endl;

    return 0;
}
