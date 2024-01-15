// Question Link:-https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/?envType=daily-question&envId=2024-01-10
/*
You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.

Each minute, a node becomes infected if:

The node is currently uninfected.
The node is adjacent to an infected node.
Return the number of minutes needed for the entire tree to be infected.



Example 1:


Input: root = [1,5,3,null,4,10,6,9,2], start = 3
Output: 4
Explanation: The following nodes are infected during:
- Minute 0: Node 3
- Minute 1: Nodes 1, 10 and 6
- Minute 2: Node 5
- Minute 3: Node 4
- Minute 4: Nodes 9 and 2
It takes 4 minutes for the whole tree to be infected so we return 4.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    int maxDistance = 0;

public:
    int amountOfTime(TreeNode *root, int start)
    {
        traverse(root, start);
        return maxDistance;
    }

    int traverse(TreeNode *root, int start)
    {
        int depth = 0;
        if (root == nullptr)
        {
            return depth;
        }

        int leftDepth = traverse(root->left, start);
        int rightDepth = traverse(root->right, start);

        if (root->val == start)
        {
            maxDistance = max(leftDepth, rightDepth);
            depth = -1;
        }
        else if (leftDepth >= 0 && rightDepth >= 0)
        {
            depth = max(leftDepth, rightDepth) + 1;
        }
        else
        {
            int distance = abs(leftDepth) + abs(rightDepth);
            maxDistance = max(maxDistance, distance);
            depth = min(leftDepth, rightDepth) - 1;
        }

        return depth;
    }
    void pre(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->val << " ";
        pre(root->left);
        pre(root->right);
    }
    void in(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }

        in(root->left);
        cout << root->val << " ";
        in(root->right);
    }
    void post(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }

        post(root->left);
        post(root->right);
        cout << root->val << " ";
    }
};

int main()
{
    TreeNode *root = new TreeNode();
    queue<TreeNode *> q;
    root->val = 1,
    q.push(root);
    vector<int> input = {5, 3, -1, 4, 10, 6, 9, 2}; // -1 denotes the null
    int i = 0;
    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();

        if (i < input.size() && input[i] != -1)
        {
            TreeNode *newnode = new TreeNode(input[i]);
            temp->left = newnode;
            q.push(newnode);
            i++;
        }
        else
        {
            i++;
        }
        if (i < input.size() && input[i] != -1)
        {
            TreeNode *newnode = new TreeNode(input[i]);
            temp->right = newnode;
            q.push(newnode);
            i++;
        }
        else
        {
            i++;
        }
    }
    int start = 3;

    Solution ss;
    ss.pre(root);
    cout << " PreOrder " << endl;
    ss.in(root);
    cout << " InOrder " << endl;
    ss.post(root);
    cout << " PostOrder " << endl;
    int ans = ss.amountOfTime(root, start);

    cout << ans << endl; // ans

    return 0;
}