void Solution::setZeroes(vector<vector<int>> &A)
{
    bool r = A[0][0], c = r;
    // r: Should the first row be set to 0? Or left as it is?
    // c: Should the first col be set to 0? Or left as it is?

    int i, j;
    for (i = 1; i < A[0].size(); ++i)
        r &= A[0][i];

    for (i = 1; i < A.size(); ++i)
        c &= A[i][0];

    // Now, the first row and col can be used to store other values.
    // A[0][0] is not used.

    // setting values for the first row ==> Traverse all the columns
    for (j = 1; j < A[0].size(); ++j)
    {
        for (i = 1; i < A.size(); ++i)
            A[0][j] &= A[i][j];
    }

    // setting values for the first col ==> Traverse all the rows
    for (i = 1; i < A.size(); ++i)
    {
        for (j = 1; j < A[0].size(); ++j)
            A[i][0] &= A[i][j];
    }

    // (r, c) == 1 iff the value in the corresponding cell in the first row and cell is 1

    for (i = 0; i < A.size(); ++i)
    {
        for (j = 0; j < A[0].size(); ++j)
            A[i][j] = A[i][0] & A[0][j];
    }

    // setting the first row's value to r.
    /* 
    If r=1, then the values must be left as it is. We must not impose 1 on the first row. It is possible, that one of the cols may contain a zero. Similar argument follows for the first col as well.

    Wrong approach:
    for (i = 0; i < A[0].size(); ++i)
        A[0][i] = r;
    */

    if (r == 0)
    {
        for (i = 0; i < A[0].size(); ++i)
            A[0][i] = 0;
    }
    // else leave the first row as it is.

    if (c == 0)
    {
        for (i = 0; i < A.size(); ++i)
            A[i][0] = 0;
    }
    // else leave the first col as it is.


    // display the answer:
    for (i = 0; i < A.size(); ++i)
    {
        for (j = 0; j < A[0].size(); ++j)
            cout << A[i][j] << " ";
        cout << endl;
    }
}
