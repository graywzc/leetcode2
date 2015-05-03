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
    bool isBalanced(TreeNode* root, int* depth)
    {
        if(root==NULL)
        {
            *depth=0; 
            return true;
        }
        else
        {
            int left,right; 
            bool ileft = isBalanced(root->left,&left); 
            bool iright = isBalanced(root->right,&right);
            *depth = max(left,right)+1;
            return ileft&&iright&&(abs(left-right)<=1);
        }
    }
    
    bool isBalanced(TreeNode* root) {
        int depth;
        return isBalanced(root,&depth);
    }
};
