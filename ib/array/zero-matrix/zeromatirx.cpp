void Solution::setZeroes(vector<vector<int>> &A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    for (int i = 0; i < A.size(); ++i)
    {
        for (int j = 0; j < A[i].size(); ++j)
        {
            if (A[i][j] != 0)
                continue;

            for (int k = 0; k < A.size(); ++k)
            {
                if (A[k][j] != 0)
                    A[k][j] = 2;
            }
            for (int k = 0; k < A[i].size(); ++k)
            {
                if (A[i][k] != 0)
                    A[i][k] = 2;
            }
        }
    }

    for (int i = 0; i < A.size(); ++i)
    {
        for (int j = 0; j < A[i].size(); ++j)
        {
            if (A[i][j] == 2)
                A[i][j] = 0;
        }
    }
}
