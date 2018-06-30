// https://www.interviewbit.com/problems/median-of-array/?ref=similar_problems
// TLE: Entire set of integers is the search space. You try to find an integer that has k-elements less that it in both the arrays. O(30*log(m+n)). idk why TLE is being generated for [1, 2, 3, 4].

double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B)
{
    int m = A.size(), n = B.size(), l = 0, r = INT_MAX, k = (m + n) / 2, cnt;
    double mid, ans1, ans2;
    while (l < r) // Do not include equality, might go into an infinte loop
    {
        mid = l + (r - l) / 2;
        cnt = 0;
        auto p = lower_bound(A.begin(), A.end(), mid);

        if (p != A.end())
            cnt = p - A.begin();

        p = lower_bound(B.begin(), B.end(), mid);
        if (p != B.end())
            cnt += p - B.begin();

        if (cnt < k)
        {
            l = mid + 1;
            continue;
        }
        else if (cnt > k)
        {
            r = mid - 1;
            continue;
        }

        // if there are odd number of elements.
        if ((m + n) & 1)
        {
            if (binary_search(A.begin(), A.end(), mid) || binary_search(B.begin(), B.end(), mid))
                return mid;

            return (double)min(*lower_bound(A.begin(), A.end(), mid), *lower_bound(B.begin(), B.end(), mid));
        }
    }

    if (binary_search(A.begin(), A.end(), mid) || binary_search(B.begin(), B.end(), mid))
        ans1 = mid;
    else
        ans1 = (double)min(*lower_bound(A.begin(), A.end(), mid), *lower_bound(B.begin(), B.end(), mid));

    // If total number of elements are even, take the average of (m + n)/2'th and ((m + n)/2 - 1) 'th element
    --k;

    int candidate1 = *(lower_bound(A.begin(), A.end(), ans1) - 1);
    int candidate2 = *(lower_bound(B.begin(), B.end(), ans1) - 1);

    cnt = 0;

    auto p = lower_bound(A.begin(), A.end(), candidate1);
    if (p != A.end())
        cnt = p - A.begin();

    p = lower_bound(B.begin(), B.end(), candidate1);

    if (p != B.end())
        cnt += p - B.begin();

    if (cnt == k)
        return (candidate1 + ans1) / 2;
    else
        return (candidate2 + ans1) / 2;
}
