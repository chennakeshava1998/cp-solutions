// https://www.interviewbit.com/problems/wave-array/

// I have sorted the values, and swapped consecutive numbers.

/*
    DOUBT:
    But how to mathematically prove mathematically that, this is the lexicographically smallest permutation?? 
*/

vector<int> Solution::wave(vector<int> &A)
{
    vector<int> v = A;
    sort(v.begin(), v.end());
    int limit;
    if (v.size() & 1)
        limit = v.size() - 1;
    else
        limit = v.size();
        
    for (int i = 0; i < limit; i += 2)
        swap(v[i], v[i + 1]);

    return v;
}