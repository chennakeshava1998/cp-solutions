/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<int> postOrder(TreeNode *A)
{
    vector<int> res;
    stack<TreeNode *> nodeStack;

    if (A == NULL)
        return res;

    nodeStack.push(A);

    if (A->right != NULL)
        nodeStack.push(A->right);

    if (A->left != NULL)
        nodeStack.push(A->left);

    while (!nodeStack.empty())
    {
        auto a = nodeStack.top();

        // Note the reverse order of pushing nodes: Actual preorder traversal is : Root, left, right. This is becoz stack stored elements in reverse order.

        if (a->right != NULL)
        {
            nodeStack.push(a->right);
            a->right = NULL;
        }
        else if (a->left != NULL)
        {
            nodeStack.push(a->left);
            a->left = NULL;
        }
        else if (a->left == NULL && a->right == NULL)
        {
            res.push_back(a->val);
            nodeStack.pop();
        }
    }

    return res;
}

void PostOrder(TreeNode *A, vector<int> &res)
{
    if (A->left != NULL)
        PostOrder(A->left, res);

    if (A->right != NULL)
        PostOrder(A->right, res);

    res.push_back(A->val);
}