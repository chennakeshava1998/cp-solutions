// not completed - https://www.interviewbit.com/problems/power-of-2/

// linearly parses through all strings from the given number to 1, dividing by 2 in each iteration. TLE.
#include <bits/stdc++.h>
using namespace std;

bool carry; // True, if the div is odd

string func(string A);
string divide(char div);
string clearLeadingZeros(string);
bool isPowerOfTwo(string);

bool isPowerOfTwo(string A)
{
    carry = 0;
    if (A == "1" || A == "0")
        return 0;

    while (1)
    {
        if (A == "1")
            return 1;

        if (A != "1" && ((A[A.size() - 1] - 48) & 1))
            return 0;

        A = func(A);
    }
}

string clearLeadingZeros(string A)
{
    int i = 0;
    while (A[i] == '0')
        ++i;

    string ans = A.substr(i);
    return ans;
}

string func(string A)
{
    string ans;
    for (int i = 0; i < A.size(); ++i)
    {
        ans += divide(A[i]);
    }

    ans = clearLeadingZeros(ans);

    return ans;
}

string divide(char div)
{
    string temp;
    if (carry)
    {
        temp += "1";
        carry = 0;
    }

    temp += div;

    // does a carry occur for the current division?
    if ((temp[temp.size() - 1] - 48) & 1) // is the last digit odd?
        carry = 1;                        // useful for the next operation

    stringstream ss(temp);
    int x = 0;
    ss >> x;

    x /= 2;

    // Clearing the contents of the stringstream. clear() method is inherited in the ios class for clearing the error bit of the streams. It's not used for emptying the contents. If EOF file is reached, then error bit will be set to 1 in such streams. But clear() method will reset it back to 0.

    ss.str(string()); // Or: ss.str(""); ===> Empties the stream

    ss.clear(); // Clears the flags
    ss << x;
    string ans = ss.str();

    return ans;
}

int main()
{
    carry = 0;
    string inp;
    cin >> inp;

    cout << isPowerOfTwo(inp) << endl;
    // cout << carry << endl;

    return 0;
}