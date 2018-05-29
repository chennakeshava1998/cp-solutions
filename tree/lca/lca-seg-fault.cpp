
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool findElem(TreeNode* A, int x);
TreeNode *solve(TreeNode* A, int B, int C, bool &flag1, bool &flag2);

TreeNode *solve(TreeNode* A, int B, int C, bool &flag1, bool &flag2) // finds the LCA
{
	if(A->val == B)
	{
		flag1 = 1;
		return A;
	}

	if(A->val == C)
	{
		flag2 = 1;
		return A;
	}
	
	TreeNode *leftLca = solve(A->left, B, C, flag1, flag2);
	TreeNode *rightLca = solve(A->right, B, C, flag1, flag2);

	if(leftLca != NULL && rightLca != NULL)
		return A;

	if(leftLca == NULL)
		return rightLca;
	else
		return leftLca; 
}

// verifies if the answer discovered by solve-method is correct, checks if both the elems are present.
int Solution::lca(TreeNode* A, int B, int C) {

    bool flag1 = 0, flag2 = 0;
	if(A == NULL)
		return -1;

	TreeNode *ans = solve(A, B, C, flag1, flag2);

	if((flag1 == 1 && flag2 == 1) && (flag1 == 1 && findElem(ans, C) || flag2 == 1 && findElem(ans, B)))
		return ans->val;

	return -1;

}

bool findElem(TreeNode* A, int x)
{
	if(A == NULL)
		return 0;

	if(A->val == x)
		return 1;

	if(findElem(A->left, x) || findElem(A->right, x))
		return 1;
	else 
		return 0;
}


/* ======================================================================================= */
// Attempt-2 : Wrong O/P fr some test-cases

// https://www.geeksforgeeks.org/lowest-common-ancestor-binary-tree-set-1/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool findElem(TreeNode* A, int x);



int Solution::lca(TreeNode* A, int B, int C) {

    // need to ensure that both the elements are present in the tree
	if(findElem(A, B) == 0 || findElem(A, C) == 0)
		return -1; // One or more of the keys is not present.

	if(A == NULL)
		return -1;

	// if any of the input nodes are encountered first, then it is the lca
	if(A->val == B || A->val == C)
		return A->val;

	int leftLca = lca(A->left, B, C);
	int rightLca = lca(A->right, B, C);

	if(leftLca > 0 && rightLca > 0) // B and C are present in either of the sub trees
		return A->val;
	else if(rightLca < 0) // both the keys are present in the left subtree
		return lca(A->left, B, C);
	else 
		return lca(A->right, B, C);
}

bool findElem(TreeNode* A, int x)
{
	if(A == NULL)
		return 0;

	if(A->val == x)
		return 1;

	if(findElem(A->left, x) || findElem(A->right, x))
		return 1;
	else 
		return 0;
}

/* ======================================================================================= */
// Attempt-3 : Seg fault


int findPath(int, vector<int>&, TreeNode*);
int Solution::lca(TreeNode* A, int B, int C) {
    vector<int> path1, path2;
    if(findPath(B, path1, A) == 0 || findPath(C, path2, A) == 0)
        return -1;
        
    int i;
    for(i=0;i<path1.size() && i < path2.size();++i)
    {
        if(path1[i] != path2[i])
            return path1[i-1];
    }
    
    if(path1.size() < path2.size())
        return path1[path1.size() - 1];
    else
        return path2[path2.size() - 1];
}

int findPath(int b, vector<int>& path, TreeNode* A)
{
    if(A == NULL)
        return 0;
        
    path.push_back(A->val); // assuming b is found in the subtree of A
    
    if(A->val == b)
        return 1;
        
    if( (A->left && findPath(b, path, A->left)) || (A->right && findPath(b, path, A)))
        return 1;
        
    // b is not present in  A's subtree, hence remove A from path 
    path.pop_back();
    
    return 0;
}

/* ======================================================================================= */
// Attempt-4 : Seg fault, geeks for geeks


bool findElem(Node* A, int x);
Node * LCA (Node* A, int B, int C) {

    // need to ensure that both the elements are present in the tree
	if(findElem(A, B) == 0 || findElem(A, C) == 0)
		return NULL; // One or more of the keys is not present.

	if(A == NULL)
		return NULL;

	// if any of the input nodes are encountered first, then it is the lca
	if(A->data == B || A->data == C)
		return A;

	Node * leftLca = LCA(A->left, B, C);
	Node * rightLca = LCA(A->right, B, C);

	if(leftLca != NULL && rightLca != NULL) // B and C are present in either of the sub trees
		return A;
	else if(rightLca == NULL) // both the keys are present in the left subtree
		return LCA(A->left, B, C);
	else 
		return LCA(A->right, B, C);
}

bool findElem(Node* A, int x)
{
	if(A == NULL)
		return 0;

	if(A->data == x)
		return 1;

	if(findElem(A->left, x) || findElem(A->right, x))
		return 1;
	else 
		return 0;
}

/* ======================================================================================= */
// Attempt-5 : Seg fault, geeks for geeks


int search_node(Node* node, int n1, int n2);
Node * LCA(Node* root ,int n1 ,int n2 )
{
	if(root == NULL)
		return NULL;


	if(root != NULL && search_node(root, n1, n2) != (n1 + n2))
   		return NULL;

   	if(root->left != NULL)
   	{
   		if(search_node(root->left, n1, n2) == (n1 + n2))
   			return LCA(root->left, n1, n2);
   	}
    
   	if(root->right != NULL)
   	{
   		if(search_node(root->right, n1, n2) == (n1 + n2))
   			return LCA(root->right, n1, n2);
   	}

   	return root;
}

int search_node(Node* node, int n1, int n2)
{
	int val = 0;
	if(node->data == n1)
		val += n1;
	else if(node->data == n2)
		val += n2;

	if(node->left != NULL)
		val += search_node(node->left, n1, n2);

	if(node->right != NULL)
		val += search_node(node->right, n1, n2);

	return val;
}


