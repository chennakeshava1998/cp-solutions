/*
vector<int> inOrderA, inOrderB, preOrderA, preOrderB;

void inOrder(TreeNode *A, bool flag)
{
    if (A == NULL)
        return;

    inOrder(A->left, flag);
    if (flag == 0)
        inOrderA.push_back(A->val);
    else
        inOrderB.push_back(A->val);

    inOrder(A->right, flag);
}

void preOrder(TreeNode *A, bool flag)
{
    if (A == NULL)
        return;

    if (flag == 0)
        preOrderA.push_back(A->val);
    else
        preOrderB.push_back(A->val);

    preOrder(A->left, flag);
    preOrder(A->right, flag);
}

bool compareTrees(TreeNode *A, TreeNode *B)
{
    inOrder(A, 0);
    inOrder(B, 1);

    if (inOrderA != inOrderB)
        return 0;

    preOrder(A, 0);
    preOrder(B, 1);

    if (preOrderA != preOrderB)
        return 0;

    return 1;
}
*/

bool compareTrees(TreeNode *A, TreeNode *B)
{
    if (A == NULL && B == NULL)
        return 1;

    if (A == NULL && B != NULL)
        return 0;

    if (A != NULL && B == NULL)
        return 0;

    if (A->val != B->val)
        return 0;

    bool a = compareTrees(A->left, B->left);
    bool b = compareTrees(A->right, B->right);

    return a & b;
}