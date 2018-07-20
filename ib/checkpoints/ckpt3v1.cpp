#include <bits/stdc++.h>
using namespace std;

int numRange(vector<int> &A, int B, int C)
{
    // Always initialise all variables.
    int i = 0, j = 0, b_ptr = 0, c_ptr = 0, sum = 0, c_sum = 0, b_sum = 0, ans = 0;

    for (; i < A.size() && b_ptr < A.size(); b_sum -= A[i], c_sum -= A[i], ++i)
    {
        if (b_ptr < i)
        {
            b_sum = 0;
            b_ptr = i;
        }

        j = b_ptr;
        sum = b_sum;

        while (sum < B && j < A.size())
        {
            sum += A[j];
            ++j;
        }

        b_ptr = j - 1;
        b_sum = sum;

        if (c_ptr < i)
        {
            c_sum = 0;
            c_ptr = i;
        }

        j = c_ptr;
        sum = c_sum;

        while (sum <= C && j < A.size())
        {
            sum += A[j];
            ++j;
        }

        c_ptr = j;
        c_sum = sum;

        ans += (c_ptr - b_ptr);
        cout << "i = " << i << "\t"
             << "c = " << c_ptr << "\t"
             << "b = " << b_ptr << endl;
    }

    return ans;
}

int main()
{
    vector<int> A = {10, 5, 1, 0, 2};
    int B = 6, C = 8;

    cout << numRange(A, B, C) << endl;

    return 0;
}