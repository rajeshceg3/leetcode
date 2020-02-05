class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
		int n = A.size()/2;
		std::unordered_set<int> hash_set;
		for(const auto& slice: A)
		{
			if( hash_set.count(slice) == 0) hash_set.insert(slice);
			else return slice;
		}		
        return 0;
    }
};
