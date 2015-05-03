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
    void sumNumbers(TreeNode* root, int *n, int *sum)
    {
        assert(root);    
        if(root->left==NULL && root->right==NULL)
            *sum += *n*10 + root->val;
        else
        {
            *n = *n*10 + root->val;
            if(root->left!=NULL)
                sumNumbers(root->left, n, sum);
            if(root->right!=NULL)
                sumNumbers(root->right, n, sum);
            *n /= 10;
        }
    }

    int sumNumbers(TreeNode* root) {
        int sum=0, n=0;               
        if(root==NULL)
            return sum;
        sumNumbers(root,&n,&sum);
        return sum;
    }
};
