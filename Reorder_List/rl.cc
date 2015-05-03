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
    ListNode* reverseList(ListNode *head)
    {
        if(head == NULL || head->next == NULL) 
            return head;

        ListNode *cur = head;
        ListNode *prev = NULL;
        while(cur)
        {
            ListNode *next = cur->next; 
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    void reorderList(ListNode *head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL)
            return;    

        ListNode *p1 = head;
        ListNode *p2 = head;
        while(p2->next && p2->next->next)
        {
            p1 = p1->next;  
            p2 = p2->next->next;
        }

        p1->next = reverseList(p1->next);

        p2 = p1->next; 
        p1->next = NULL;
        while(p2)
        {
            p1 = p2->next; 
            p2->next = head->next;
            head->next = p2;
            head = p2->next;
            p2 = p1;
        }
    }
};
