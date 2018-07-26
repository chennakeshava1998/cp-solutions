// https://www.interviewbit.com/problems/level-order/

// Memory efficient than using a queue and performing BFS.
// All traversals visit the children from left to right


void inorder(TreeNode *A, int depth, vector<vector<int>> &Nodes)
{
    if (A->left != NULL)
        inorder(A->left, depth + 1, Nodes);

    Nodes[depth].push_back(A->val);

    if (A->right != NULL)
        inorder(A->right, depth + 1, Nodes);
}

vector<vector<int>> findLevelOrder(TreeNode *A)
{
    vector<vector<int>> Nodes;

    if (A == NULL)
        return Nodes;

    Nodes.resize(pow(10, 3) + 1);

    inorder(A, 0, Nodes);

    return Nodes;
}