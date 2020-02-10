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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
    if(!root) return {};
	std::queue<std::pair<int,TreeNode*>> aqueue;
	std::multimap<int,TreeNode*> result;
	aqueue.push(make_pair(0,root));
    int sugar;
	while(!aqueue.empty())
	{
		auto tmp = aqueue.front();
		sugar = tmp.first + 1;
		result.insert(tmp);
		aqueue.pop();
        if(tmp.second->left)
		    aqueue.push(make_pair(sugar,tmp.second->left));
        if(tmp.second->right)
		    aqueue.push(make_pair(sugar,tmp.second->right));	
	}
    
	vector<vector<int>> finale;
	finale.resize(sugar);
	
	int index = 0;
	while( index <= sugar)
	{
		for( const auto& slice:result)
			if(slice.first == index) finale[index].emplace_back(slice.second->val);
		index++;
	}
	return finale;        
    }
};
