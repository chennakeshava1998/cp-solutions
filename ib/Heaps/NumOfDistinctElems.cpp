// https://www.interviewbit.com/problems/distinct-numbers-in-window/
void disp(map<int, int>);
void disp(map<int, int> m)
{
    for (auto it = m.begin(); it != m.end(); ++it)
        cout << (it->first) << "\t" << (it->second) << endl;
}

vector<int> Solution::dNums(vector<int> &A, int B)
{
    vector<int> ans;
    if (B > A.size())
        return ans; // returning an empty array
    int i = 0, cnt = 0;

    map<int, int> m;
    // building the initial map

    for (; i < B; ++i)
        m[A[i]]++;

    // for (auto it = m.begin(); it != m.end(); ++it)
    //     if ((it->second) > 0)
    //         ++cnt;

    i = B;
    ans.push_back(m.size());

    int k = 0; // LHS pointer to the previous frame.
    // No. if distinct elements in the previous frame.
    // cnt holds the number of distinct elements in the current frame.

    cnt = m.size();

    for (; i < A.size(); ++i, ++k)
    {
        if (A[i] == A[k])
        {
            // nothing changes in the map or the cnt.
            ans.push_back(cnt);
            continue;
        }

        m[A[k]]--;
        if (m[A[k]] == 0) // k is no longer found in this range.
            --cnt;

        // A[i] is a newly encountered element.
        if (m[A[i]] == 0)
            ++cnt;

        m[A[i]]++;

        ans.push_back(cnt);
    }

    return ans;
}