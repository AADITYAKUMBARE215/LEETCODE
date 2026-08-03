// LeetCode 145: Binary Tree Postorder Traversal
// Approach: Recursive DFS (Left -> Right -> Root)
// Time: O(n)
// Space: O(h)

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
    void postorder(TreeNode* root, vector<int>& post)
    {
        if (root == nullptr)
            return;

        postorder(root->left, post);
        postorder(root->right, post);
        post.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> post;
        postorder(root, post);
        return post;
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
    vector<int> ans = obj.postorderTraversal(root);

    cout << "Postorder Traversal: ";

    for (int val : ans)
    {
        cout << val << " ";
    }

    cout << endl;

    return 0;
}