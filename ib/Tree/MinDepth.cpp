// https://www.interviewbit.com/problems/min-depth-of-binary-tree/

int findMinDepth(TreeNode *A, int currDepth)
{
    if (A == NULL)
        return 0;

    if (A->left == NULL && A->right == NULL)
        return currDepth;

    int a = 1e9, b = 1e9;

    if (A->left)
        a = findMinDepth(A->left, currDepth + 1);

    if (A->right)
        b = findMinDepth(A->right, currDepth + 1);

    return min(a, b);
}