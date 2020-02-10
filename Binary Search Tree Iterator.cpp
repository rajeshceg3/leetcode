/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
	vector<int> nums;
    int m_index = 0;
    int m_size;
	void recurse(TreeNode* root)
	{
		if (root == nullptr) return;
		recurse(root->left);
		nums.emplace_back(root->val);
		recurse(root->right);		
	}
public:
    BSTIterator(TreeNode* root) {
		recurse(root);
        m_size = nums.size();
    }
    
    /** @return the next smallest number */
    int next() {
        return nums[m_index++];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return m_index < m_size;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
