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
	bool isSymmetricUtil(TreeNode* left,TreeNode* right )
	{
		if (!left || !right) return left == right;
		if (left->val != right->val) return false;
		return isSymmetricUtil(left->left,right->right) && isSymmetricUtil(left->right,right->left);				
	}
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
		return isSymmetricUtil(root->left,root->right);
    }
};
