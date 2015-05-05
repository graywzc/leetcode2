// recursive
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
    ListNode* reverseList(ListNode* head) {
        ListNode* newhead = head;
        while(head && head->next)    
        {
            newhead = reverseList(head->next);                     
            head->next->next = head;
            head->next = NULL;
        }
        return newhead;
    }
};
