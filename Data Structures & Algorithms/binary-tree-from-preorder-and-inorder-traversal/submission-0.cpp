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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        return build(preorder, inMap, preIdx, 0, inorder.size() - 1);
    }
private:
    TreeNode* build(vector<int>& preorder, unordered_map<int, int>& inMap, int& preIdx, int left, int right) {
        if (left > right) return nullptr;
        int rootVal = preorder[preIdx++];
        TreeNode* root = new TreeNode(rootVal);
        int inIdx = inMap[rootVal];
        
        root->left = build(preorder, inMap, preIdx, left, inIdx - 1);
        root->right = build(preorder, inMap, preIdx, inIdx + 1, right);
        return root;
    }
};