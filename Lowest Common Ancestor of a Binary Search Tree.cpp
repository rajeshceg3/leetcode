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
void findpath(TreeNode* root, int interest, vector<int>& result)
{
    result.emplace_back(root->val);
    if ( root->val == interest) return;
    else if ( root->val > interest) findpath(root->left,interest,result);
    else if ( root->val < interest) findpath(root->right,interest,result);		
}
TreeNode* findnode(TreeNode* root, int interest)
{
    TreeNode* search = nullptr;
    if ( root->val == interest) return root;        
    else if ( root->val > interest) search = root->left;
    else if ( root->val < interest) search = root->right;
    return findnode(search,interest);
}	
public:
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if ( p->val == q->val) return p;
    vector<int> p_path,q_path;
    findpath(root,p->val,p_path);
    findpath(root,q->val,q_path);

    int index = 0;
    int p_size = p_path.size();
    int q_size = q_path.size();		   
    while(( index < p_size )
      && ( index < q_size )
      && ( p_path[index] == q_path[index] ))
    index++;
    return findnode(root,p_path[index-1]);
}
};
