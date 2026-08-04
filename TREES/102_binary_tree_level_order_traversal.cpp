// LeetCode 102: Binary Tree Level Order Traversal
// Approach: Breadth-First Search (BFS)
// Time: O(n)
// Space: O(n)

#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <string>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        val = x;
        left = right = nullptr;
    }
};

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> ans;

        if (root == nullptr)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if (node->left != nullptr)
                    q.push(node->left);

                if (node->right != nullptr)
                    q.push(node->right);
            }

            ans.push_back(level);
        }

        return ans;
    }
};

TreeNode* buildTree(const vector<string>& nodes)
{
    if (nodes.empty() || nodes[0] == "null")
        return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < nodes.size())
    {
        TreeNode* curr = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != "null")
        {
            curr->left = new TreeNode(stoi(nodes[i]));
            q.push(curr->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != "null")
        {
            curr->right = new TreeNode(stoi(nodes[i]));
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

int main()
{
    cout << "Enter level order traversal (use 'null' for missing nodes):\n";

    string line;
    getline(cin, line);

    stringstream ss(line);
    vector<string> nodes;
    string x;

    while (ss >> x)
    {
        nodes.push_back(x);
    }

    TreeNode* root = buildTree(nodes);

    Solution obj;
    vector<vector<int>> ans = obj.levelOrder(root);

    cout << "Level Order Traversal:\n";

    for (const auto& level : ans)
    {
        cout << "[ ";
        for (int val : level)
        {
            cout << val << " ";
        }
        cout << "]\n";
    }

    return 0;
}