/*
Not working for test-case:

Input:
4
20 10 L 10 5 L 5 2 L 2 3 R

Its Correct output is:
1

And Your Code's output is:
0

*/

// previous value, encountered during the inorder traversal
int prev_inorder_val = -1;
bool isBST(Node *root);
bool inOrder(Node *root);

bool inOrder(Node *root)
{
    // empty trees are considered as bst
    // to prevent de referencing of NULL nodes:
    if (root == NULL)
        return 1;

    // both left and right subtrees must be bst

    if (inOrder(root->left) == 0)
        return 0;

    // Before right subtree is checked
    // the root's value must be atleast prev_inorder_val
    if (root->data < prev_inorder_val)
        return 0;
    else // update prev_inorder_val for next comparison
        prev_inorder_val = root->data;

    if (inOrder(root->right) == 0)
        return 0;

// return 1 is all above conditions are met
    return 1;
}

bool isBST(Node *root)
{
    prev_inorder_val = -1;
    // the above stmt ensures that all test cases start afresh.
    // Without the above stmt, the previous inorder values will be carried over to the successive test cases! 
    return inOrder(root);
}
