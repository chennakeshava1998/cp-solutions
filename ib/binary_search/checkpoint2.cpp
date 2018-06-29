// https://www.interviewbit.com/problems/prettyprint/

void disp(vector<vector<int>> &v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = 0; j < v[0].size(); ++j)
            cout << v[i][j] << " ";
        cout << endl;
    }
}

vector<vector<int>> Solution::prettyPrint(int A)
{
    int mid = A - 1, i, j, k;

    vector<vector<int>> v(2 * A - 1);
    vector<int> temp;

    j = A;
    while (j >= 1)
        temp.push_back(j--);

    j = 2;
    while (j <= A)
        temp.push_back(j++);

    for (i = 0; i < v.size(); ++i)
        v[i] = temp;

    disp(v);

    k = 2;
    for (i = mid - 1; i >= 0; --i)
    {
        for (j = 0; j < v[i].size(); ++j)
        {
            if (v[i][j] < k)
                v[i][j] = k;
        }
        ++k;
    }

    k = 2;
    for (i = mid + 1; i < v.size(); ++i)
    {
        for (j = 0; j < v[i].size(); ++j)
        {
            if (v[i][j] < k)
                v[i][j] = k;
        }
        ++k;
    }

    disp(v);

    return v;
}
