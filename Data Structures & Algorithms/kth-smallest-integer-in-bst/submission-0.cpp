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
    int kthSmallest(TreeNode* root, int k) {
        int res = -1;
        dfs(root, k, res);
        return res;
    }
private:
    void dfs(TreeNode* node, int& k, int& res) {
        if (!node) return;
        dfs(node->left, k, res);
        k--;
        if (k == 0) {
            res = node->val;
            return;
        }
        dfs(node->right, k, res);
    }
};