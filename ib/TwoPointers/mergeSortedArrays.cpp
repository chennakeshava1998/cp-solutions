// https://www.interviewbit.com/problems/merge-two-sorted-lists-ii/
void Solution::merge(vector<int> &A, vector<int> &B)
{
    int i = A.size() - 1, j = B.size() - 1, k = A.size() + B.size() - 1;

    A.resize(k + 1);

    while (i >= 0 && j >= 0)
    {
        if (A[i] > B[j])
        {
            A[k] = A[i];
            --i;
        }
        else
        {
            A[k] = B[j];
            --j;
        }
        --k;
    }

    while (i >= 0)
    {
        A[k] = A[i];
        --i;
        --k;
    }

    while (j >= 0)
    {
        A[k] = A[j];
        --j;
        --k;
    }
}
