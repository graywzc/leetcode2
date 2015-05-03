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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL)
            return NULL;

        ListNode* dummy = new ListNode(0);                 
        dummy->next = head;

        ListNode* cur = head;
        while(cur->next)
        {
            ListNode* p = dummy; 
            while(cur->next->val > p->next->val)
                p = p->next;

            if(p!=cur)
            {
                ListNode* next = cur->next; 
                cur->next = next->next;
                next->next = p->next;
                p->next = next;
            }
            else
            {
                cur=cur->next; 
            }
        }

        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};
