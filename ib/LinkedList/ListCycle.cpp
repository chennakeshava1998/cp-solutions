
// https://www.interviewbit.com/problems/list-cycle/
// Hashing method: O(N) memory. Check out: Floyd's two ptr algorithm
map<ListNode *, bool> m;
ListNode *findCycle(ListNode *A, bool val)
{
    if (!A)
        return A;

    m[A] = val;

    if (m.count(A->next))
        return A->next;

    return findCycle(A->next, !val);
}
