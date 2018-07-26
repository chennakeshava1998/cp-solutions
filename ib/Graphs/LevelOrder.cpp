// Queues cannot be traversed using iterators. Use a deque for that purpose.
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<vector<int>> levelOrderTraversal(TreeNode *A);

vector<vector<int>> levelOrderTraversal(TreeNode *A)
{
    // back_up_q keeps a copy of 'q'. It is used to find out the maximum depth of the tree. The size of the 2D matrix can be allocated accordingly.
    // Data structures to perform BFS
    queue<pair<TreeNode *, int>> q;
    vector<vector<int>> levelOrderNodes(pow(10, 3) + 1);

    int max_tree_depth = 0;

    q.push({A, 0});
    // back_up_q.push({A, 0});

    // Breadth First Search
    while (!q.empty())
    {
        auto a = q.front().first;
        auto b = q.front().second;

        max_tree_depth = max(max_tree_depth, b);

        levelOrderNodes[b].push_back(a->val);

        q.pop(); // Is this valid way to remove the front element from queue??

        // Check if the child exists, seg fault alert!!
        if (A->left != NULL)
        {
            q.push({A->left, b + 1});
            // back_up_q.push({A->left, b + 1});
        }

        if (A->right != NULL)
        {
            q.push({A->right, b + 1});
            // back_up_q.push({A->right, b + 1});
        }
    }

    levelOrderNodes.resize(max_tree_depth + 1);

    // for (auto it = back_up_q.begin(); it != back_up_q.end(); ++it)
    //     levelOrderNodes[it->second].push_back((it->first)->val);

    // while (!back_up_q.empty())
    // {
    //     auto a = back_up_q.front().first;
    //     auto b = back_up_q.front().second;

    //     levelOrderNodes[b].push_back(a->val);
    // }

    return levelOrderNodes;
}

vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    return levelOrderTraversal(A);
}
