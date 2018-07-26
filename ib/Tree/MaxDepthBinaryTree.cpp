
void dfs(TreeNode *A, int depth, int &max_depth);

void dfs(TreeNode *A, int depth, int &max_depth)
{
    if (A == NULL)
        return;

    max_depth = max(max_depth, depth);

    if ((A->left) != NULL)
        dfs(A->left, depth + 1, max_depth);

    if ((A->right) != NULL)
        dfs(A->right, depth + 1, max_depth);
}
