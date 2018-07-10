/*
    Q2 Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
    You should preserve the original relative order of the nodes in each of the two partitions.
    For example,
    Given 1->4->3->2->5->2 and x = 3,
    return 1->2->2->4->3->5.
*/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    struct Node *next;
    /* data */
};

struct Node *split(struct Node *, int x);
struct Node *insert(int val);
void disp(struct Node *);

void disp(struct Node *HEAD)
{
    auto p = HEAD;
    while (p != NULL)
    {
        cout << (p->val) << " ";
        p = p->next;
    }
    cout << endl;
}

struct Node *insert(int val)
{
    // Syntax for new: pointer-var = new data-type;
    struct Node *p = new struct Node;
    p->val = val;
    p->next = NULL;
    return p;
}

struct Node *split(struct Node *HEAD, int x)
{
    vector<int> less, more;

    // traversing through the LL
    auto p = HEAD;
    while (p != NULL)
    {
        if (p->val < x)
            less.push_back(p->val);
        else
            more.push_back(p->val);
        p = p->next;
    }

    p = HEAD;

    for (int i = 0; i < less.size(); ++i, p = p->next)
        p->val = less[i];

    for (int i = 0; i < more.size(); ++i, p = p->next)
        p->val = more[i];

    return HEAD;
}

int main()
{
    int n, x, splitVar;
    cin >> n >> splitVar;
    struct Node *HEAD = NULL, *CURR = NULL;

    cin >> x;
    HEAD = insert(x);

    CURR = HEAD;

    for (int i = 0; i < (n - 1); ++i) // already inserted one element
    {
        cin >> x;
        auto p = insert(x);
        CURR->next = p;
        CURR = p;
    }

    split(HEAD, splitVar);

    disp(HEAD);

    return 0;
}