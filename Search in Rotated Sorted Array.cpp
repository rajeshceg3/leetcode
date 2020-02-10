class Solution {
public:
    int search(vector<int>& nums, int target) {
        int result = -1;
        auto it = std::find(begin(nums),end(nums),target);        
        if ( it != end(nums))  result = std::distance(begin(nums),it);        
        return result;
    }
};
