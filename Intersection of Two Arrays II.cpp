class Solution {
public:
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
std::sort(begin(nums1),end(nums1));
std::sort(begin(nums2),end(nums2));
vector<int> result;
vector<int>::iterator n1_it = begin(nums1);
vector<int>::iterator n2_it = begin(nums2);

while( n1_it != end(nums1) && n2_it != end(nums2))
{
    if (*n1_it < *n2_it) n1_it++;
    else if(*n1_it > *n2_it) n2_it++;        
    else
    {
        result.emplace_back(*n1_it);
        n1_it++;
        n2_it++;		
    }
}
return result;    
}
};
