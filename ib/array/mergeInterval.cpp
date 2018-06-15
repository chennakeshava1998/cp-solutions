/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
// O(n^2) answer

bool mergeable(Interval a, Interval b);
bool mergeable(Interval a, Interval b)
{

    if (a.start > b.end || a.end < b.start)
        return 0;

    return 1;
}

vector<Interval> Solution::merge(vector<Interval> &A)
{
    set<Interval> s;
    for (i = 0; i < A.size(); ++i)
        s.insert(A[i]);

    
}
