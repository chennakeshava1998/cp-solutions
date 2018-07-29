void disp(const vector<vector<int>> &A)
{
    for (int i = 0; i < A.size(); ++i)
    {
        for (int j = 0; j < A[0].size(); ++j)
            cout << A[i][j] << " ";
        cout << endl;
    }
}

int findMinHealth(vector<vector<int>> A)
{
    vector<vector<int>> initHealth(A.size(), vector<int>(A[0].size(), 0));
    int m = A.size(), n = A[0].size(), i, j, temp_right, temp_down;

    if (A[m - 1][n - 1] >= 0)
        initHealth[m - 1][n - 1] = 0;
    else
        initHealth[m - 1][n - 1] = abs(A[m - 1][n - 1]);

    // last column
    j = n - 1;
    for (i = m - 2; i >= 0; --i)
    {
        temp_down = initHealth[i + 1][j] - A[i][j];
        temp_down = max(0, temp_down);

        initHealth[i][j] = temp_down;
    }

    // last row
    i = m - 1;
    for (j = n - 2; j >= 0; --j)
    {
        temp_right = initHealth[i][j + 1] - A[i][j];
        temp_right = max(0, temp_right);
        initHealth[i][j] = temp_right;
    }

    for (i = m - 2; i >= 0; --i)
    {
        // cout<<"i = "<<i<<"\n\n";
        for (j = n - 2; j >= 0; --j)
        {

            temp_down = 1e9;
            temp_right = 1e9;

            temp_down = initHealth[i + 1][j] - A[i][j];
            temp_down = max(0, temp_down);

            temp_right = initHealth[i][j + 1] - A[i][j];
            temp_right = max(0, temp_right);

            initHealth[i][j] = min(temp_down, temp_right);

            // if(i==0)
            // {
            //     cout<<i<<"\t"<<j<<endl;
            //     cout<<"right: "<<temp_right<<"\t"<<"down: "<<"\t"<<temp_down<<endl;
            // }
        }
    }

    // disp(initHealth);

    return initHealth[0][0] + 1;
}

int Solution::calculateMinimumHP(vector<vector<int>> &A)
{
    return findMinHealth(A);
}
