/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
private:
    int dfs(TreeNode* node, int maxSoFar) {
        if (!node) return 0;
        int res = (node->val >= maxSoFar) ? 1 : 0;
        maxSoFar = max(maxSoFar, node->val);
        res += dfs(node->left, maxSoFar);
        res += dfs(node->right, maxSoFar);
        return res;
    }
};