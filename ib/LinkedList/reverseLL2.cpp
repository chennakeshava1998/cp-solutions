/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *movePointer(ListNode *A, int B);
void func(ListNode *A, int B);

ListNode *movePointer(ListNode *A, int B)
{
    // Index is 1-based, according to the question
    ListNode *ptr = A;
    while (B--)
        ptr = ptr->next;

    return ptr;
}

// B is the difference between the left and right boundaries
void func(ListNode *A, int B)
{
    ListNode *ptr = A;
    stack<int> st;
    ++B;
    while (B--)
    {
        st.push(ptr->val);
        ptr = ptr->next;
    }

    ptr = A;

    while (!st.empty())
    {
        ptr->val = st.top();
        ptr = ptr->next;
        st.pop();
    }
}

ListNode *Solution::reverseBetween(ListNode *A, int B, int C)
{
    // Working with 0-based indices
    --B;
    --C;
    ListNode *ptr = movePointer(A, B);

    func(ptr, C - B);

    return A;
}
