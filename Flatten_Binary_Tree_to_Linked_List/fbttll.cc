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
    TreeNode* flat(TreeNode *root)
    {
        assert(root!=NULL); 
        if(root->left==NULL && root->right==NULL)
            return root;
        else if(root->left == NULL)
            return flat(root->right);
        else if(root->right == NULL)
        {
            root->right = root->left; 
            root->left = NULL;
            return flat(root->right);
        }
        else
        {
            TreeNode* left = flat(root->left); 
            TreeNode* right = flat(root->right); 
            left->right = root->right;
            root->right = root->left;
            root->left = NULL;
            return right;
        }
    }
    void flatten(TreeNode *root) {
        if(root == NULL)
            return;
        flat(root);            
    }
};
