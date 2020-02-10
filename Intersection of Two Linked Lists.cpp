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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if( !headA || !headB) return nullptr;
        std::unordered_set<ListNode*> valueA;
        while(headA)
        {
            valueA.insert(headA);
            headA = headA->next;
        }

        while(headB)
        {
            if(valueA.count(headB) != 0) return headB;
            headB = headB->next;
        }
        return nullptr;
    }
};
