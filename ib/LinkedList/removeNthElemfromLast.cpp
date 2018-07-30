// https://www.interviewbit.com/problems/remove-nth-node-from-list-end/

// Aliter: IMP: use two pointers at a distance of 'n'. Delete the second ptr, when the first reaches the end of the LL.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int lenOfLinkedList(ListNode *A)
{
    ListNode *ptr = A;
    int cnt = 0;

    while (ptr != NULL)
    {
        ++cnt;
        ptr = ptr->next;
    }

    return cnt;
}

ListNode *Solution::removeNthFromEnd(ListNode *A, int B)
{
    int size = lenOfLinkedList(A);

    if (B >= size)
    {
        A = A->next;
        return A;
    }

    if (B == 0)
        B = 1;

    int cnt = 0;
    B = size - B;

    ListNode *ptr = A;
    while (cnt < B)
    {
        if (cnt == (B - 1))
        {
            ptr->next = ptr->next->next;
            break;
        }

        ptr = ptr->next;
        ++cnt;
    }

    return A;
}
