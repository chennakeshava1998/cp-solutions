// https://www.interviewbit.com/problems/vertical-order-traversal-of-binary-tree/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void dfs(TreeNode *A, map<string, vector<int>> &m, string path);
void findVecDim(map<string, vector<int>> m, int &max_left, int &max_right);

void findVecDim(map<string, vector<int>> m, int &max_left, int &max_right)
{
    max_left = 0;
    max_right = 0;

    for (auto it = m.begin(); it != m.end(); ++it)
    {
        if (!(it->second).empty() && *((it->second).begin()) == 'l')
            max_left = max(max_left, (int)(it->second).size());

        if (!(it->second).empty() && *((it->second).begin()) == 'r')
            max_right = max(max_right, (int)(it->second).size());
    }
}

void dfs(TreeNode *A, map<string, vector<int>> &m, string path)
{
    if (A == NULL)
        return;

    m[path].push_back(A->val);

    if (path == "")
    {
        dfs(A->left, m, "l");
        dfs(A->right, m, "r");
    }
    else
    {
        if (path[path.size() - 1] == 'l')
        {
            dfs(A->left, m, path + "l");
            dfs(A->right, m, path.substr(1));
        }
        else
        {
            dfs(A->left, m, path.substr(1));
            dfs(A->right, m, path + "r");
        }
    }
}

int main()
{

    return 0;
}