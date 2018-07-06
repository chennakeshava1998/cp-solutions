string Solution::longestCommonPrefix(vector<string> &A)
{
    int cnt = 0, i;
    bool flag = 1;
    string s;

    // important to check for empty corner case inputs.
    if (A.empty())
        return s;

    while (flag)
    {
        char temp;
        if (cnt < A[0].size())
            temp = A[0][cnt];
        else
        {
            flag = 0;
            break;
        }

        for (i = 1; i < A.size(); ++i)
        {
            if (cnt < A[i].size())
            {
                if (A[i][cnt] != temp)
                {
                    flag = 0;
                    break;
                }
            }
            else
            {
                flag = 0;
                break;
            }
        }

        if (!flag)
            break;

        ++cnt;
    }

    for (i = 0; i < cnt; ++i)
        s += A[0][i];

    return s;
}
