
// O(N) solution
int Solution::diffPossible(vector<int> &A, int B)
{
    // Corner Case: Clarify this with the interviewer
    if (A.size() <= 1)
        return 0;

    int i, j = 0;
    // Always initialise all variables, uninitialised variables are very hard to live with.
    for (i = 0; i < A.size(); ++i)
    {
        j = max(i + 1, j);
        while (j < A.size() && (A[j] - A[i] < B))
            ++j;

        if (A[j] - A[i] == B)
            return 1;
    }

    return 0;
}

/* O(NlogN) solution
    int Solution::diffPossible(vector<int> &A, int B)
    {
        // Corner Case: Clarify this with the interviewer
        if (A.size() <= 1)
            return 0;

        // tight bounds on binary_search range, B can be equal to zero.
        for (int i = A.size() - 1; i >= 0; --i)
            if (binary_search(A.begin(), A.end(), A[i] - B))
                if (lower_bound(A.begin(), A.end(), A[i] - B) != (A.begin() + i))
                    return 1;

        return 0;
    }
*/
