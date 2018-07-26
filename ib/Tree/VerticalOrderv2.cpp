/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void findDim(TreeNode *A, int &left, int &right);
int left_dist, right_dist;
int findMinLeftWidth(TreeNode *A);
int findMinRightWidth(TreeNode *A);

int findMinLeftWidth(TreeNode *A)
{
    /* 
    Recursive Version: Causes "Memory Limit Exceeded"
    
    if ((A->left) != NULL)
        return 1 + findMinLeftWidth(A->left);
    return 0;
    */

    auto it = A;
    int cnt = 0;
    while ((it->left) != NULL)
    {
        ++cnt;
        it = it->left;
    }

    return cnt;
}

int findMinRightWidth(TreeNode *A)
{
    /*
    Recursive Version: Memory Limit Exceeded
    if ((A->right) != NULL)
        return 1 + findMinRightWidth(A->left);
    return 0;
    */

    auto it = A;
    int cnt = 0;
    while ((it->right) != NULL)
    {
        it = it->right;
        ++cnt;
    }

    return cnt;
}

void findDim(TreeNode *A, int path_index)
{
    if (A == NULL)
        return;

    if (path_index > 0)
        right_dist = max(right_dist, path_index);
    else
        left_dist = min(left_dist, path_index);

    findDim(A->left, path_index - 1);
    findDim(A->right, path_index + 1);
}

vector<vector<int>> bfs(TreeNode *A)
{
    vector<vector<int>> res;

    if (A == NULL)
        return res;

    findDim(A, 0);              // updates the values of left_dist and right_dist
    left_dist = abs(left_dist); // making it positive.
    res.resize(left_dist + right_dist + 1);
    queue<pair<TreeNode *, int>> q;

    q.push({A, 0});
    while (!q.empty())
    {
        auto a = q.front().first;
        auto b = q.front().second;
        q.pop();

        res[b + left_dist].push_back(a->val);

        // Check if the children really exist!!
        if ((a->left) != NULL)
            q.push({a->left, b - 1});

        if ((a->right) != NULL)
            q.push({a->right, b + 1});
    }

    return res;
}

vector<vector<int>> Solution::verticalOrderTraversal(TreeNode *A)
{
    left_dist = 0;
    right_dist = 0;
    return bfs(A);
}
