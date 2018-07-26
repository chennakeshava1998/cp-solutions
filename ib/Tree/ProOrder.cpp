/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<int> preOrder(TreeNode *A)
{
    vector<int> preOrderNodes;
    stack<TreeNode *> st;

    if (A == NULL)
        return preOrderNodes;

    st.push(A);

    while (!st.empty())
    {
        auto a = st.top();
        st.pop();
        preOrderNodes.push_back(a->val);

        // Note the reverse order of pushing nodes: Actual preorder traversal is : Root, left, right. This is becoz stack stored elements in reverse order.

        if (a->right != NULL)
            st.push(a->right);

        if (a->left != NULL)
            st.push(a->left);
    }

    return preOrderNodes;
}