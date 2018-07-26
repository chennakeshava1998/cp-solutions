map<int, vector<int>> m;
void dfs(TreeNode *A, int hd)
{
    if (A == NULL)
        return;

    m[hd].push_back(A->val);

    dfs(A->left, hd - 1);
    dfs(A->right, hd + 1);
}

vector<vector<int>> map2vec(map<int, vector<int>> m)
{
    auto it = m.begin();
    vector<vector<int>> ans;

    for (; it != m.end(); ++it)
        ans.push_back(it->second);

    return ans;
}