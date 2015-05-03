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
    void maxPathSum(Node *node, int &mps, int &mrs)
    {
        if(node->left==NULL && node->right==NULL) 
        {
            mps = node->val;  
            mrs = node->val;
        }
        else if(node->left==NULL)
        {
            int rmps, rmrs;
            maxPathSum(node->right, rmps, rmrs);   
            int pmps = node->val + ((rmrs>0)?rmrs:0);
            mps = max(rmps, pmps);
            mrs = pmps;
        }
        else if(node->right==NULL)
        {
            int lmps, lmrs; 
            maxPathSum(node->left, lmps, lmrs);
            int pmps = node->val + ((lmrs>0)?lmrs:0);
            mps = max(lmps, pmps);
            mrs = pmps;
        }
        else
        {
            int lmps, lmrs, rmps, rmrs; 
            maxPathSum(node->left, lmps, lmrs);
            maxPathSum(node->right, rmps, rmrs);
            int pmps = node->val + ((lmrs>0)?lmrs:0) + ((rmrs>0)?rmrs:0); 
            mps = max(max(lmps, rmps), pmps);
            mrs = node->val + ((max(lmrs,rmrs)>0)?max(lmrs,rmrs):0);
        }
    }
    int maxPathSum(TreeNode *root) {
        if(root)
        {
            int mps, mrs;     
            maxPathSum(root, mps, mrs);
            return mps;
        }
        else
            return 0;
    }
};
