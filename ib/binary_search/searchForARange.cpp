// https://www.interviewbit.com/problems/search-for-a-range/
vector<int> Solution::searchRange(const vector<int> &A, int B)
{
    vector<int> v; // vector to be returned
    // Push -1 twice into v.
    v.push_back(-1);
    v.push_back(-1);

    auto l = lower_bound(A.begin(), A.end(), B);

    // The below condition implies that the element is not found in the array.
    if (*l != B)
        return v;

    v[0] = l - A.begin();

    // finding the RHS boundary
    auto e = upper_bound(A.begin(), A.end(), B);

    // Both the endpoints of the range are inclusive and must point to the element B. Hence subtracting '1' from upper_bound limit.
    v[1] = e - A.begin() - 1;

    return v;
}
