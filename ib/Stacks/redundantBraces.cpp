int Solution::braces(string A)
{
    // Do not compare A[i] with "some_char"; A[i] is considered as a pointer, and the single-character within double quotes is considered as an integer.

    stack<int> st;
    int i = 0;

    for (; i < A.size(); ++i)
    {
        if (A[i] == '(')
            st.push('(');
        else if (A[i] == '+' || A[i] == '-' || A[i] == '*' || A[i] == '/')
            st.push(A[i]);
        else if (A[i] == ')')
        {
            if (st.top() == '(')
                return 1;
            else
            {
                while (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/')
                    st.pop();

                st.pop();
            }
        }
    }

    return 0;
}
