/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Uses Stack, 2 passes
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

// ====================================================
// Approach-2: Change the links

ListNode *left_kick, *right_kick, *first_left_parent;
ListNode *movePointer(ListNode *A, int B);
void func(ListNode *A, int B);

ListNode *movePointer(ListNode *A, int B)
{
    // Index is 1-based, according to the question
    ListNode *ptr = A;
    while (B--)
    {
        left_kick = ptr;
        ptr = ptr->next;
    }

    return ptr;
}

void func(ListNode *A, int B)
{
    ++B;
    ListNode *ptr = A;
    while (B--)
    {
        right_kick = ptr->next;
        ptr->next = left_kick;
        left_kick = ptr;
        ptr = right_kick;
    }

    first_left_parent->next = left_kick;
    A->next = ptr;
}

ListNode *Solution::reverseBetween(ListNode *A, int B, int C)
{
    // Handling this case separately, if B==C, then left_kick's value will not be updated.
    if (B == C)
        return A;
    // Working with 0-based indices
    --B;
    --C;
    left_kick = NULL;
    right_kick = NULL;
    ListNode *ptr = movePointer(A, B);

    first_left_parent = left_kick;

    func(ptr, C - B);

    return A;
}
