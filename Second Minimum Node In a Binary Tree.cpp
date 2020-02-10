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
    vector<int> result;
    void traverse(TreeNode* root)
    {
		if ( root == nullptr) return;
		traverse(root->left);
		result.emplace_back(root->val);
		traverse(root->right);        
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        traverse(root);
        std::sort(begin(result),end(result));
        auto it = std::unique(begin(result),end(result));
        result.erase(it,end(result));
        for(const auto& slice: result) cout<<slice<<" ";
        if ( result.size() >= 2) return result[1];
        return -1;
    }
};
