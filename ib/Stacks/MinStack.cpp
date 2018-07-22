// https://www.interviewbit.com/problems/min-stack/

stack<int> st;
stack<int> min_elem;

MinStack::MinStack()
{
    while (!st.empty())
        st.pop();

    while (!min_elem.empty())
        min_elem.pop();

    cout << "Cleared the stacks\n";
}

void MinStack::push(int x)
{
    st.push(x);
    // The empty() conditions are very important.
    if ((!min_elem.empty() && x < min_elem.top()) || min_elem.empty())
        min_elem.push(x);
    else
        min_elem.push(min_elem.top());

    cout << "Push: " << x << endl;
}

void MinStack::pop()
{
    if (st.empty())
        return;

    st.pop();
    min_elem.pop();

    cout << "Popped" << endl;
}

int MinStack::top()
{
    if (st.empty())
        return -1;

    return st.top();

    cout << "Top call: " << st.top() << endl;
}

int MinStack::getMin()
{
    if (st.empty())
        return -1;

    return min_elem.top();
    cout << "Min elem: " << min_elem.top() << endl;
}
