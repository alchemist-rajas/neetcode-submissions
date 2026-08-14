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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "N,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string s;
        for (char c : data) {
            if (c == ',') {
                q.push(s);
                s = "";
            } else {
                s += c;
            }
        }
        return build(q);
    }
private:
    TreeNode* build(queue<string>& q) {
        string s = q.front();
        q.pop();
        if (s == "N") return nullptr;
        
        TreeNode* root = new TreeNode(stoi(s));
        root->left = build(q);
        root->right = build(q);
        return root;
    }
};