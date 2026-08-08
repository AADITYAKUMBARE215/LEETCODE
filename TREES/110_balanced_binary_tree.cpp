// LeetCode 110: Balanced Binary Tree
// Approach: Bottom-Up Recursive DFS
// Time: O(n)
// Space: O(h)

#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <string>
#include <cmath>
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
    int height(TreeNode* root)
    {
        if (root == nullptr)
            return 0;

        int left = height(root->left);
        if (left == -1)
            return -1;

        int right = height(root->right);
        if (right == -1)
            return -1;

        if (abs(left - right) > 1)
            return -1;

        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root)
    {
        return height(root) != -1;
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

    if (obj.isBalanced(root))
        cout << "Balanced: true" << endl;
    else
        cout << "Balanced: false" << endl;

    return 0;
}