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
    TreeNode* buildTree(const vector<int>& inorder,
                        int istart,
                        int iend,
                        const vector<int>& postorder,
                        int pstart,
                        int pend)
    {
        if(istart>iend) 
            return NULL;
        else if(istart == iend)
        {
            TreeNode *root = new TreeNode(inorder[istart]);
            return root;
        } 
        else
        {
            TreeNode *root = new TreeNode(postorder[pend]); 
            int i = istart;
            while(inorder[i]!=postorder[pend])
                i++;
            root->left = buildTree(inorder,istart,i-1,postorder,pstart,i-1-istart+pstart);
            root->right = buildTree(inorder,i+1,iend,postorder,i-istart+pstart,pend-1);
            return root;
        }
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);            
    }
};
