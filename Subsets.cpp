class Solution {
	void backtrack(vector<int>& nums,vector<vector<int>>& res, vector<int> subset, int k)
	{
		if( k == nums.size())
		{
			res.push_back(subset);
			return;
		}
		backtrack(nums,res,subset,k+1);
		subset.push_back(nums[k]);
		backtrack(nums,res,subset,k+1);
	}
public:
    vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> subset;
		backtrack(nums, res,vector<int>(),0);
		return res;        
    }
};
