// not completed - https://www.interviewbit.com/problems/power-of-2/

#include <bits/stdc++.h>
using namespace std;

bool odd, carry; // True, if the div is odd

int func(string A);
string divide(string div);

int func(string A)
{

   
}

string divide(string div)
{
    string temp;
    if (carry)
    {
        temp += "1";
        carry = 0;
    }

    temp += div;
    stringstream ss(temp);
    int x = 0;
    ss >> x;

    x /= 2;

    if (x & 1)
    {
        odd = 1;
        return "";
    }

    // Clearing the contents of the stringstream. clear() method is inherited in the ios class for clearing the error bit of the streams. It's not used for emptying the contents. If EOF file is reached, then error bit will be set to 1 in such streams. But clear() method will reset it back to 0.

    ss.str(string()); // Or: ss.str(""); ===> Empties the stream

    ss.clear(); // Clears the flags
    ss << x;
    string ans = ss.str();

    return ans;
}

int main()
{

    odd = 0;
    carry = 0;
    string inp;
    cin >> inp;

    cout << divide(inp, 0) << endl;

    return 0;
}