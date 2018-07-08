// https://www.interviewbit.com/problems/implement-strstr/
// haystack, needle
int Solution::strStr(const string A, const string B)
{
    int i = 0, j, pos = -1;
    if (B == "" || A == "")
        return pos;

    for (i = 0; i < A.size(); ++i)
    {
        if (A[i] == B[0])
        {
            int k = 1; // index for the needle
            j = i + 1; // index for the haystack
            while (A[j] == B[k] && (k < B.size()) && (j < A.size()))
            {
                ++j;
                ++k;
            }

            if (k == B.size())
            {
                pos = i;
                break;
            }
        }
    }

    return pos;
} 