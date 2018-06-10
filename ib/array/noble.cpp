int Solution::solve(vector<int> &A)
{
    int i;
    vector<int> v = A;
    sort(v.begin(), v.end());

    int len = A.size();
    
    for (i = 0; i < len; ++i)
    {
        /* 
            IMP: v.size() - i - 1 is wrong logic. Even if identical elements are present to the RHS, they will be considered as GREATER ELEMENTS.
            Input: 2 2 2 2
            For the first 2, according to this logic, the numbers of elements to the RHS = 4 - 0 - 1 = 3.
            IMP: But NOT all the elements to the RHS are greater than the current element
        */
        // optimal to do upper bound search from i till end, since the array is already sorted. 
        if (v.end() - upper_bound(v.begin() + i, v.end(), v[i]) == v[i])
            return 1;
    }

    return -1;
}