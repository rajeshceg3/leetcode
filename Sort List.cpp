/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
    if (!head) return nullptr;
    vector<int> nums;
    while(head)
    {
        nums.emplace_back(head->val);
        head = head->next;
    }
    std::sort(begin(nums),end(nums));

    ListNode* first = new ListNode(nums[0]);
    ListNode* result = first;

    for( int index = 1; index < nums.size();index++)
    {
        ListNode* tmp = new ListNode(nums[index]);
        first->next = tmp;
        first = first->next;			
    }
    return result;        
    }
};
