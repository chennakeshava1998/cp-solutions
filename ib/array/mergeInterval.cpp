/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

vector<Interval> Solution::merge(vector<Interval> &A)
{
    // sorting the array
    int i, j;
    for (i = 0; i < A.size(); ++i)
    {
        for (j = i + 1; j < A.size(); ++j)
        {
            if (A[i].start > A[j].start)
                swap(A[i], A[j]);
        }
    }
}
