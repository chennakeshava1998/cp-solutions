// https://www.interviewbit.com/problems/reorder-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

vector<ListNode *> get_address(ListNode *A)
{
    vector<ListNode *> ans;
    while (A != NULL)
    {
        ans.push_back(A);
        A = A->next;
    }

    return ans;
}

void test_get_address(vector<ListNode *> addr)
{
    for (auto i : addr)
        cout << "Value : " << i->val << endl;
}

ListNode *reorder_list(vector<ListNode *> addr)
{
    int l = 0, r = addr.size() - 1;

    while (l < r)
    {
        addr[r]->next = addr[l]->next;

        if (addr[r]->next == addr[r])
            addr[r]->next = NULL;

        addr[l]->next = addr[r];

        ++l;
        --r;
    }

    if (l == r)
        addr[l]->next = NULL;

    return addr[0];
}

ListNode *Solution::reorderList(ListNode *A)
{
    vector<ListNode *> addr = get_address(A);

    // test_get_address(addr);

    if (addr.size() <= 2)
        return A;

    return reorder_list(addr);
}
