// DP attempt
map<TreeNode *, int> m; // depth of the subtree rooted at the first ptr
int findSubTreeDepth(TreeNode *A)
{
    if (A == NULL)
        return 0;

    // already calculated the subtree depth previouly
    if (m.count(A))
        return m[A];

    // base case, leaf node
    if (A->left == NULL && A->right == NULL)
    {
        return (m[A] = 1);
    }

    m[A] = 1 + max(findSubTreeDepth(A->left), findSubTreeDepth(A->right));

    return m[A];
}

bool checkBalance(TreeNode *A)
{
    if (A == NULL)
        return 1;

    int depthLeftSubTree = findSubTreeDepth(A->left);
    int depthRightSubTree = findSubTreeDepth(A->right);

    if (abs(depthLeftSubTree - depthRightSubTree) > 1)
        return 0;

    bool leftCheck = checkBalance(A->left);
    bool rightCheck = checkBalance(A->right);

    return leftCheck & rightCheck;
}

// O(N^2) solution
// Brute Force way to find the depth of a tree
int findMaxdepth(TreeNode *A)
{
    if (A == NULL)
        return 0;

    return 1 + max(findMaxdepth(A->left), findMaxdepth(A->right));
}

bool checkBalance(TreeNode *A)
{
    if (A == NULL)
        return 1;

    int depthLeftSubTree = findMaxdepth(A->left);
    int depthRightSubTree = findMaxdepth(A->right);

    if (abs(depthLeftSubTree - depthRightSubTree) > 1)
        return 0;

    bool leftCheck = checkBalance(A->left);
    bool rightCheck = checkBalance(A->right);

    return leftCheck & rightCheck;
}