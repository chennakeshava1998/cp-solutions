/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// https://www.interviewbit.com/problems/invert-the-binary-tree/?ref=similar_problems

void copyTreeNode(TreeNode *A, TreeNode *B)
{

    B->val = A->val;

    if (A->left == NULL && A->right == NULL)
        return;

    if (!A->left)
    {
        TreeNode *right_child = new TreeNode(0);
        B->right = right_child;

        // initialization
        right_child->left = NULL;
        right_child->right = NULL;
        copyTreeNode(A->left, right_child);
    }

    if (!A->right)
    {
        TreeNode *left_child = new TreeNode(0);
        B->left = left_child;

        left_child->left = NULL;
        left_child->right = NULL;

        copyTreeNode(A->right, left_child);
    }
}

TreeNode *Solution::invertTree(TreeNode *A)
{
    if (A == NULL)
        return A;

    TreeNode *ans = new TreeNode(0);
    ans->val = A->val;
    ans->left = NULL;
    ans->right = NULL;

    if (A->left)
    {
        TreeNode *right_child = new TreeNode(0);
        right_child->left = NULL;
        right_child->right = NULL;
        ans->right = right_child;
        copyTreeNode(A->left, right_child);
    }

    if (A->right)
    {
        TreeNode *left_child = new TreeNode(0);
        left_child->left = NULL;
        left_child->right = NULL;
        ans->left = left_child;
        copyTreeNode(A->right, left_child);
    }


    return ans;
}
