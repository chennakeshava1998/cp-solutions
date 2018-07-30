
ListNode *removeDuplicates(ListNode *A)
{
    ListNode *ptr = A;

    while (ptr)
    {
        ListNode *temp = ptr->next;

        while (temp && (temp->val == ptr->val))
            temp = temp->next;

        ptr->next = temp;
        ptr = temp;
    }

    return A;
}