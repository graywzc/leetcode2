/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// using morris traversal to achieve O(1) space
class Solution {
public:
    void recoverTree(TreeNode *root) {
        typedef TreeNode Node;
        if(root==NULL) return;
        Node *cur = root;

        Node *swap1=NULL;
        Node *swap2=NULL;
        Node *pred=NULL;

        while(cur)
        {
            if(cur->left == NULL)
            {
                // do  
                if(pred && cur->val<pred->val) 
                {
                    if(swap1==NULL) 
                    {
                        swap1 = pred; 
                        swap2 = cur;
                    }
                    else
                    {
                        swap2 = cur; 
                    }
                }
                pred = cur;

                cur = cur->right;
            }
            else
            {
                // find prev node  
                Node *prev = cur->left;
                while(prev->right && prev->right!=cur)
                    prev = prev->right;
                
                if(prev->right==NULL)
                {
                    prev->right = cur; 
                    cur = cur->left;
                }
                else
                {
                    // do
                    if(cur->val < pred->val) 
                    {
                        if(swap1==NULL) 
                        {
                            swap1 = pred; 
                            swap2 = cur;
                        }
                        else
                        {
                            swap2 = cur; 
                        }
                    }
                    pred = cur;

                    prev->right = NULL; 
                    cur = cur->right;
                }
            }
        }
           
        assert(swap1 && swap2);
        int temp = swap1->val;
        swap1->val = swap2->val;
        swap2->val = temp;
    }
};
