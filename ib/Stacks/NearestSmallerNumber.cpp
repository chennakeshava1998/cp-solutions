vector<int> Solution::prevSmaller(vector<int> &A)
{
    stack<int> st;
    vector<int> g;

    for (int i = 0; i < A.size(); ++i)
    {
        // equality is a corner case.
        while (!st.empty() && (A[st.top()] >= A[i]))
            st.pop();

        if (st.empty())
        {
            g.push_back(-1);
            st.push(i);
            continue;
        }

        g.push_back(A[st.top()]);
        st.push(i);
    }

    return g;
}