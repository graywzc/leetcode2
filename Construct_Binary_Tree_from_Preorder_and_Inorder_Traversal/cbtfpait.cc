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
    TreeNode* buildTree(const vector<int>& preorder, 
                        int pstart,
                        int pend,
                        const vector<int>& inorder,
                        int istart,
                        int iend)
    {
        if(pstart>pend) 
            return NULL;
        else if(pstart == pend)
        {
            TreeNode *root = new TreeNode(preorder[pstart]); 
            return root;
        }
        else
        {
            TreeNode *root = new TreeNode(preorder[pstart]); 
            int i = istart;
            while(inorder[i]!=preorder[pstart])
                i++;

            root->left = buildTree(preorder,pstart+1,pstart-istart+i,inorder,istart,i-1);
            root->right = buildTree(preorder,pstart-istart+i+1,pend,inorder,i+1,iend);
        }
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);            
    }
};
