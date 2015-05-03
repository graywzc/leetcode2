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
        int la = 0, lb = 0;
        ListNode* cur = headA;
        while(cur)
        {
            la++; 
            cur = cur->next;
        }
        cur = headB;
        while(cur)
        {
            lb++;
            cur = cur->next;
        }
        ListNode* cur1;
        if(la>lb)
        {
            int count = la-lb; 
            cur = headA;
            while(count>0)
            {
                cur = cur->next; 
                count--;
            }
            cur1 = headB;
        }
        else
        {
            int count = lb-la; 
            cur1 = headB;
            while(count>0)
            {
                cur1 = cur1->next; 
                count--;
            }
            cur = headA;
        }

        while(cur && cur1)
        {
            if(cur == cur1) 
                return cur;

            cur = cur->next;
            cur1 = cur1->next;
        }
        return NULL;
    }
};
