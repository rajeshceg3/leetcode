class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int len = nums.size();
        for(int index = 0; index < len; index++)
        {
            if(index == 0 && nums[index+1] < nums[index]) return 0;
            if(index == len-1 && nums[index] > nums[index-1]) return len-1;
            
            if( (index != 0) &&
                (index != len-1)&&
               ((nums[index] > nums[index-1] && nums[index] > nums[index+1]))
              ) return index;
        }
        return 0;
        
    }
};
