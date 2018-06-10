// some error in the platform, the first cout stmt is not being executed
vector<int> Solution::maxset(vector<int> &A)
{
    cout << "hello!\n";
    int sum = -1, i, n = A.size(), len = -1, start;
    vector<int> ans;
    vector<int> temp;
    vector<int> v = A;
    cout << "hello2!\n";
    for (i = n - 1; i >= 0; --i)
    {
        if (v[i] < 0)
        {
            if (accumulate(temp.begin(), temp.end(), 0) > sum || accumulate(temp.begin(), temp.end(), 0) == sum && temp.size() > len)
            {
                ans.clear();
                copy(temp.begin(), temp.end(), ans.begin());
                sum = accumulate(ans.begin(), ans.end(), 0);
                len = ans.size();
                start = i + 1;

                cout << "ans array:\n";
                for (i = 0; i < ans.size(); ++i)
                    cout << ans[i] << " ";
                cout << "\n";
            }

            temp.clear();
        }
        else
            temp.push_back(v[i]);
    }

    if (accumulate(temp.begin(), temp.end(), 0) > sum || accumulate(temp.begin(), temp.end(), 0) == sum && temp.size() > len)
    {
        ans.clear();
        copy(temp.begin(), temp.end(), ans.begin());
        sum = accumulate(ans.begin(), ans.end(), 0);
        len = ans.size();
        start = i + 1;
    }

    cout << "ans array:\n";
    for (i = 0; i < ans.size(); ++i)
        cout << ans[i] << " ";
    cout << "\n";

    return ans;
}
