// https://www.interviewbit.com/problems/max-continuous-series-of-1s/
vector<int> Solution::maxone(vector<int> &A, int B)
{
    int cnt = B, i = 0, j = 0, pos = 1e9, ans = 0;

    // Enclosing multiple characters within single-quotes causes portability problems. This is tantamount to having multiple chars within an integer variable.
    // cout << 'j' << "\t" << 'i' << "\t" << 'ans' << "\t" << 'pos' << endl;
    // cout << "j"
    //      << "\t"
    //      << "i"
    //      << "\t"
    //      << "ans"
    //      << "\t"
    //      << "pos" << endl;

    while (i < A.size() && j < A.size())
    {
        while (A[j] == 1 && j < A.size())
            ++j;

        if (j < A.size())
        {
            if ((j - i + 1) > ans)
            {
                pos = i;
                ans = j - i + 1;
            }
        }
        else if ((j - i) > ans)
        {
            pos = i;
            ans = j - i;
        }

        if (A[j] == 0 && j < A.size() && cnt == 0)
        {
            ++j;
            i = j;
            continue;
        }

        if (A[j] == 0 && j < A.size())
        {
            if (cnt > 0)
            {
                --cnt;
                ++j;
            }

            else
            {
                // moving i'th pointer past the first zero in the window.
                while (A[i] == 1 && i < A.size())
                    ++i;

                // A[i] is now zero. But it's not required in the window.
                if (i < A.size())
                    ++i; // Moving past the first zero within the window

                ++cnt;
            }
        }

        if (j < A.size())
        {
            if ((j - i + 1) > ans)
            {
                pos = i;
                ans = j - i + 1;
            }
        }
        else if ((j - i) > ans)
        {
            pos = i;
            ans = j - i;
        }

        // cout << j << "\t" << i << "\t" << ans << "\t" << pos << endl;
    }

    vector<int> temp;

    while (ans--)
    {
        temp.push_back(pos);
        ++pos;
    }

    return temp;
}