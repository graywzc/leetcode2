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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n) return head;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *anc = dummy;
        while(m>1)
        {
            anc = anc->next; 
            m--;
            n--;
        }
        
        ListNode *prev = anc->next;
        ListNode *cur = prev->next;
        while(n>1)
        {
            ListNode *next = cur->next;    
            cur->next = prev;
            prev = cur;
            cur = next;
            n--;
        }
        
        anc->next->next = cur;
        anc->next = prev;
        
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};
