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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL )                
            return NULL;

        ListNode *p1 = head;
        ListNode *p2 = head;

        bool isCycle = false;
        while(p2->next && p2->next->next)
        {
            p1 = p1->next; 
            p2 = p2->next->next;
            if(p1 == p2)
            {
                isCycle = true;
                break;
            }
        }

        if(!isCycle)
            return NULL;

        if(p1 == head) 
            return head;
        else
        {
            p1 = head; 
            while(p1!=p2)
            {
                p1=p1->next;
                p2=p2->next;
            }
            return p1;
        }

    }
};
