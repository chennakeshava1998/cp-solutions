vector<int> Solution::maxset(vector<int> &A)
{
    int i, j;
    vector<vector<int>> v;
    vector<int> temp;
    // splitting the vector at negative number points.
    for (i = 0; i < A.size(); ++i)
    {
        if (A[i] >= 0)
            temp.push_back(A[i]);
        else
        {
            if (!temp.empty())
            {
                v.push_back(temp);
                temp.clear();
            }
        }
    }
    
    if(!temp.empty())
        v.push_back(temp);

    int global_sum = -1, global_len = -1;
    vector<int> ans;

    for (i = v.size() - 1; i >= 0; --i)
    {
        if (accumulate(v[i].begin(), v[i].end(), 0) > global_sum)
        {
            ans.clear();
            ans = v[i];
        }
        else if (accumulate(v[i].begin(), v[i].end(), 0) == global_sum && v[i].size() > global_len)
        {
            ans.clear();
            ans = v[i];
        }
    }

    

    return ans;
}

/*
cout << "v array:\t" << v.size() << endl;
    for (i = 0; i < v.size(); ++i)
    {
        cout << i << "\t" << v[i].size() << endl;
        for (int j = 0; j < v[i].size(); ++j)
            cout << v[i][j] << " ";
        cout << endl;
    }
    
    for(i=0;i<ans.size();++i)
        cout << ans[i] << " ";
    cout << endl;
*/