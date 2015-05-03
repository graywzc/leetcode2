/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    typedef TreeNode Node;
    bool isValidBST(Node* node, int& max, int& min)
    {
        max = min = node->val;
        if(node->left)            
        {
            int lmax,lmin;
            bool lvalid = isValidBST(node->left, lmax, lmin);
            if(node->val<lmax || !lvalid)
                return false;
            min = lmin; 
        }
        if(node->right)
        {
            int rmax, rmin; 
            bool rvalid = isValidBST(node->right, rmax, rmin); 
            if(node->val>rmin || !rvalid)
                return false;
            max = rmax;
        }
        return true;
    }

    bool isValidBST(TreeNode *root) {
        if(root==NULL)
            return true;
        int max,min;
        return isValidBST(root, max, min);    
    }
};
