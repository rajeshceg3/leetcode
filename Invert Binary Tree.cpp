/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void inverter(TreeNode* root)
    {
        if (!root) return;
        swap(root->left,root->right);
        inverter(root->left);
        inverter(root->right);        
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        inverter(root);
        return root;
    }
};
