/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {

        typedef TreeLinkNode Node;
        Node *row_start = root;
        while(row_start)
        {
            Node* cur = row_start; 
            row_start = NULL;
            Node* prev = NULL;
            while(cur)
            {   
                if(cur->left!=NULL)
                {
                    if(row_start==NULL) 
                    {
                        prev = cur->left; 
                        row_start = prev;
                    }
                    else
                    {
                        prev->next = cur->left; 
                        prev = prev->next;
                    }
                }
                if(cur->right!=NULL)
                {
                    if(row_start==NULL) 
                    {
                        prev = cur->right; 
                        row_start = prev;
                    }
                    else
                    {
                        prev->next = cur->right;      
                        prev = prev->next;
                    }
                }
                cur = cur->next; 
            }
        }
    }
};
