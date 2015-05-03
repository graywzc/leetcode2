//
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode** phead, int l)
    {
        if(l == 0) 
            return NULL;
        else
        {
            TreeNode* left = sortedListToBST(phead,(l-1)/2); 
            TreeNode* root = new TreeNode((*phead)->val);
            root->left = left;
            *phead = (*phead)->next;
            root->right = sortedListToBST(phead,l-1-(l-1)/2);
            return root;
        }
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int l = 0;
        ListNode* cur = head;
        while(cur)
        {
            l++;
            cur = cur->next;
        }

        return sortedListToBST(&head,l);
    }
};
