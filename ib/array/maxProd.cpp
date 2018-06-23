// https://www.interviewbit.com/problems/maxspprod/

int Solution::maxSpecialProduct(vector<int> &v)
{
    int n = v.size();
    vector<int> left(n, 0);

    stack<int> st;
    st.push(0);
    for (auto i = 1; i < n - 1; ++i)
    {
        while (!st.empty() && v[st.top()] <= v[i])
            st.pop();

        if (st.empty())
            left[i] = 0;
        else
            left[i] = v[st.top()];

        st.push(i);
    }

    // st.clear(); There is no such thing as clear() method for stacks
    while (!st.empty())
        st.pop();

    st.push(n - 1);

    for (auto i = n - 1; i > 0; --i)
    {
        while (v[st.top()] <= v[i])
            st.pop();

        if (st.empty())
            left[i] = 0;
        else
            left[i] *= v[st.top()];

        st.push(i);
    }

    for (auto u : left)
        cout << u << " ";
    cout << endl;

    return *max_element(left.begin(), left.end());
}
