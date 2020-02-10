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
	void inorder(TreeNode* root,vector<int>& result)
	{
        if(root == nullptr) return;
		inorder(root->left,result);
		result.emplace_back(root->val);
		inorder(root->right,result);
	}
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
		vector<int> vec1,vec2;
		inorder(root1,vec1);
		inorder(root2,vec2);
		vector<int> result_vec;
		result_vec.resize(vec1.size() + vec2.size());
		auto it = std::move(begin(vec1),end(vec1),begin(result_vec));
        std::move(begin(vec2),end(vec2),it);
		std::inplace_merge(begin(result_vec),it,end(result_vec));
		return result_vec;
    }
};
