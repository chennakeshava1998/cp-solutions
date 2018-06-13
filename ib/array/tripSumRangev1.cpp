int Solution::solve(vector<string> &A)
{
    vector<vector<float>> v(4, vector<float>());
    int i;

    for (i = 0; i < A.size(); ++i)
    {
        const char *p = A[i].c_str();
        float temp = atof(p);

        if (temp > 2)
            continue;

        if (temp < 0.333)
            v[0].push_back(temp);
        else if (temp < 0.666)
            v[1].push_back(temp);
        else if (temp < (float)1)
            v[2].push_back(temp);
        else if (temp < 1.333)
            v[3].push_back(temp);
    }

    for (i = 0; i < 4; ++i)
        sort(v[i].begin(), v[i].end());

    cout << "values:\n";
    for (i = 0; i < 4; ++i)
    {
        cout << i << "\n";
        for (int j = 0; j < v[i].size(); ++j)
            cout << v[i][j] << " ";
        cout << "\n\n";
    }

    // 5 cases

    if (v[1].size() >= 3)
    {
        float temp = v[1][v[1].size() - 1] + v[1][v[1].size() - 2] + v[1][v[1].size() - 3];

        if (temp > 1 && temp < 2)
            return 1;
    }

    if (v[0].size() >= 2 && v[3].size() >= 1)
    {
        float temp = v[0][0] + v[0][1] + v[3][0];
        cout << "case1\n\n";
        if (temp > 1 && temp < 2)
            return 1;
    }

    if (v[0].size() >= 2 && v[2].size() >= 1)
    {
        float temp = v[2][v[2].size() - 1] + v[0][1] + v[0][1];
        cout << "case2\n\n";
        if (temp > 1 && temp < 2)
            return 1;
    }

    if (!v[2].empty() && v[1].size() >= 2)
    {
        cout << "case3\n\n";
        float temp = v[2][v[2].size() - 1] + v[1][1] + v[1][0];
        if (temp > 1 && temp < 2)
            return 1;
    }

    if (!v[0].empty() && !v[1].empty() && !v[2].empty())
    {
        cout << "case4\n\n";
        float temp = v[2][v[2].size() - 1] + v[1][v[1].size() - 1] + v[0][v[0].size() - 1];
        if (temp > 1 && temp < 2)
            return 1;
    }

    return 0;
}