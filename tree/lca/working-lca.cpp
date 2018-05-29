/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int ANS; // do not globally initialize the ANS variable, some test cases do not pass, why??

int dfs(TreeNode* x, int a, int b)
{
	if(x == NULL)
		return 0;

	int ans = 0;

	if(x->val == a)
		ans += 1;
	if(x->val == b)
		ans += 2;

	ans += dfs(x->left, a, b);
	ans += dfs(x->right, a, b);

	// ans == 3 ensures both the elements have been found.
	// ANS == -1 makes sure that the lowest ancestor is being considered, and not anb ancestors of LCA.
	// This is because recursion works like a stack, first LCA finishes it's fan-call, then the control is returned to it's parents. 

	if(ans == 3 && ANS == -1)
		ANS = x->val;

	return ans; // important, do not forget this stmt !!
}

int Solution::lca(TreeNode* A, int B, int C) {
	ANS = -1; // no solution is found yet
	dfs(A, B, C);
	return ANS;
}