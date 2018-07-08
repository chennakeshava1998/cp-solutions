// O(N^2) solution
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string);
bool isPalindrome(string s) // O(N), N = string's length
{
    string t = s;
    reverse(t.begin(), t.end());
    return t == s;
}

int solve(string A)
{
    int i = 0, j = A.size() - 1, cnt = 0;
    string temp = A;
    while (i < j)
    {
        if (isPalindrome(temp)) // O(N)
            break;

        if (A[i] == A[j])
            ++i;
        else
            // Need to insert another character matching A[j] at the beginning of the string
            ++cnt;

        --j;
        temp = A.substr(i, j - i + 1); // O(N)
    }

    return cnt;
}

int main()
{
    string s = "Aa";
    cout << solve(s) << endl;
    return 0;
}
