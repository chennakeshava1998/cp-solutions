// Memory limit exceeded!
void Solution::setZeroes(vector<vector<int>> &A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<int> zero(A[0].size(), 0);
    vector<int> r, c; // vector to store the indices where 0 is found.

    for (int i = 0; i < A.size(); ++i)
    {
        for (int j = 0; j < A[i].size(); ++j)
        {
            if (A[i][j] == 0)
            {
                r.push_back(i);
                c.push_back(j);
            }
        }
    }

    for (int i = 0; i < r.size(); ++i)
    {
        // replacing these rows with zero vector
        A[r[i]] = zero;
    }

    for (int j = 0; j < c.size(); ++j)
    {
        for (i = 0; i < A.size(); ++i)
            A[i][c[j]] = 0;
    }
}
