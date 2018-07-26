// Alternative approach: perform inorder traversal and verify if the resulting 1-D array is symmetric ie, first element = last element, etc.

bool compareTree(TreeNode *A, TreeNode *B)
{
    /*
    Condition checking approach-1:
    if (A == NULL && B == NULL)
        return 1;

    if (A == NULL && B != NULL)
        return 0;

    if (A != NULL && B == NULL)
        return 0;

    if (A->val != B->val)
        return 0;

    */

    /*
    Condition checking approach-2

    if (A == NULL && B == NULL)
        return 1;

    if (A == NULL || B == NULL)
        return 0;
    */

    // More elegant
    if (A == NULL || B == NULL)
        return (A == B);

    if (A->val != B->val)
        return 0;

    bool a = compareTree(A->left, B->right);
    bool b = compareTree(A->right, B->left);

    return a & b;
}

bool wrapperFunc(TreeNode *A)
{
    if (A == NULL)
        return 1;

    return compareTree(A->left, A->right);
}