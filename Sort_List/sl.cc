// Used quick sort, but exceed time limit 
/**
 * Definition for singly-linked list.
 */
#include <iostream>
#include <cstdlib>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* sortList(ListNode* head, ListNode* tail)
    {
        if(head==tail || head->next == tail)
            return head;

        ListNode* dummy = new ListNode(0); 
        dummy->next = head;

        ListNode* cur = head;
        while(cur->next != tail)
        {
            if(cur->next->val < head->val) 
            {
                ListNode* next = cur->next; 
                cur->next = next->next;
                next->next = dummy->next;
                dummy->next = next;
            }
            else
            {
                cur = cur->next; 
            }
        }

        head->next = sortList(head->next, tail); 
        dummy->next = sortList(dummy->next, head);

        head =dummy->next;
        delete dummy;
        return head;
    }

    ListNode* sortList(ListNode* head) {
        return sortList(head,NULL);
    }
};

int main()
{
    srand (time(NULL));
    ListNode *head = new ListNode(rand());
    ListNode *cur = head;
    int count = 100;
    while(count>0)
    {
        cur->next = new ListNode(rand()); 
        cur = cur->next;
        count--;
    }

    /*
    cur = head;
    while(cur)
    {
        cout<<cur->val<<' '; 
        cur = cur->next;
    }
    cout<<endl;
    */
    
    Solution s;
    ListNode *res = s.sortList(head);
    
    while(res && res->next)
    {
        if(res->val > res->next->val)
            cout<<"fail"<<endl;
        //cout<<res->val<<' '; 
        res = res->next;
    }
    cout<<"pass"<<endl;
}
