// https://www.interviewbit.com/problems/numbers-of-length-n-and-value-less-than-k/?ref=similar_problems

// O(B*log(|A|))
bool flag;
int b;
bool check(vector<int> &A)
{
    if (A[0] == 0)
        return 1;
    else
        return 0;
}

int solve(vector<int> &v, int pos, int c);

int Solution::solve(vector<int> &A, int B, int C)
{

    if (A.size() == 0) // Empty Set
        return 0;

    if (B == 0)
        return 1;

    sort(A.begin(), A.end());
    flag = check(A);
    b = B;

    // finding out the length of B
    int len_C = 0, temp = C;

    while (temp)
    {
        ++len_C;
        temp /= 10;
    }

    if (B > len_C || C == 0)
        return 0;
    else if (B < len_C)
    {
        if (flag)
            return pow(A.size(), B) - pow(A.size(), B - 1);
        else
            return pow(A.size(), B);
    }

    int sum = solve(A, B - 1, C);

    if (B == 1 && flag)
        ++sum;

    return sum;
}

int solve(vector<int> &v, int pos, int c)
{
    int sum = 0, digit = c / (int)pow(10, pos);

    auto p = lower_bound(v.begin(), v.end(), digit);

    if (p != v.begin())
    {
        if (pos == b - 1)
            sum = (p - v.begin() - (int)flag) * pow(v.size(), pos);
        else
            sum = (p - v.begin()) * pow(v.size(), pos);
    }

    if (p != v.end() && *p == digit)
        sum += solve(v, pos - 1, c);

    return sum;
}
