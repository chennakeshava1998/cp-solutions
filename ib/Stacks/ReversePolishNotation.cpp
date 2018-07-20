// https://www.interviewbit.com/problems/evaluate-expression/
#include <bits/stdc++.h>
using namespace std;

string convert_to_string(int x)
{
    stringstream ss;
    ss >> x;
    string ans = ss.str();
    return ans;
}

int convert_to_int(string s)
{
    stringstream ss(s);
    int x = 0;

    ss << x;
    return x;
}

int evalRPN(vector<string> &A)
{
    // vector<char> v;
    // for (int i = 0; i < A.size(); ++i)
    //     v[i] = A[i][0];
    stack<char> st;

    for (int i = 0; i < A.size(); ++i)
    {
        if (A[i] == "+" || A[i] == "-" || A[i] == "*" || A[i] == "/")
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();

            cout << a << "\t" << b << "\t" << A[i] << endl;

            // m cannot be char, in which case, there would be comparisons between pointer(str) and an integer(char m).
            string m = A[i];

            if (m == "+")
                st.push(a + b);
            else if (m == "-")
                st.push(b - a);
            else if (m == "*")
                st.push(a * b);
            else if (m == "/")
                st.push(b / a);
        }
        else
            st.push(stoi(A[i], nullptr));
    }

    return st.top();
}

int main()
{
    string s = "12";
    cout << convert_to_int(s) << endl;

    return 0;
}
