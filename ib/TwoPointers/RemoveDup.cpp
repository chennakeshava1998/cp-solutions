// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array-ii/
// IMP: If elements of a vector are erased, the indices of the elements will change. We will have to account for the dynamically changing indices in line 15.

/* O(N^2) solution
vector.erase() is linear in the length of the range, and the distance between the end of the range and the end of the vector.
    int Solution::removeDuplicates(vector<int> &A)
    {
        for (int i = 0; i < A.size(); ++i)
        {
            int j = i;
            while (j < (A.size() - 1) && (A[j] == A[j + 1]))
                ++j;

            cout << j << "\t" << i << "\t" << A[i] << endl;

            if ((j - i + 1) > 2)
            {
                A.erase(A.begin() + i + 2, A.begin() + j + 1);
                ++i;
            }
            else 
                i = j;
        }

        return A.size();
    }
*/

// O(N) solution ==> Two Pointers method

int Solution::removeDuplicates(vector<int> &A)
{
    int i = 0, j = 0, k = 0;
    while (i < A.size())
    {
        j = i;
        while (j < (A.size() - 1) && (A[j] == A[j + 1]))
            ++j;

        if ((j - i + 1) >= 2)
        {
            A[k] = A[i];
            A[k + 1] = A[i];
            k += 2;
        }
        else
        {
            A[k] = A[i];
            ++k;
        }

        i = j + 1;
    }

    A.erase(A.begin() + k, A.end());
    return A.size();
}