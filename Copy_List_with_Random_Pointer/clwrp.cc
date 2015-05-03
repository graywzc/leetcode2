/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        typedef RandomListNode Node;

        if(NULL == head) return NULL;
        
        Node* cur = head;
        while(cur)
        {
            Node* tmp = cur->next; 
            cur->next = new Node(cur->label);
            cur->next->next = tmp;
            cur = tmp;
        }
        cur = head;
        while(cur)
        {
            cur->next->random = cur->random?(cur->random->next):(NULL);     
            cur = cur->next->next;
        }

        cur = head;
        Node* copy = cur->next;
        while(cur)
        {
            Node* cur_copy = cur->next; 
            cur->next = cur_copy->next;
            cur_copy->next = cur_copy->next?cur_copy->next->next:NULL;
            cur = cur->next;
        }

        return copy;
    }
};
