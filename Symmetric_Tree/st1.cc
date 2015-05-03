// iterative
// inorder traversal
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
    bool isSymmetric(TreeNode *root) {
        if(root == NULL)                
            return true;

        TreeNode* left = root->left;
        TreeNode* right = root->right;

        stack<TreeNode*> stl,str;

        while(!stl.empty() || left)
        {
            if(left) 
            {
                if(!right || str.size()!=stl.size()) 
                    return false;
                stl.push(left); 
                left = left->left;
                str.push(right);
                right = right->right;
            }
            else
            {
                if(right || str.size()!=stl.size()) 
                    return false;
                left = stl.top(); 
                right = str.top();
                stl.pop();
                str.pop();
                if(left->val!=right->val)
                    return false;
                left = left->right;
                right = right->left;
            }
        }

        if(!str.empty() || right)
            return false;

        return true;

        
    }
};
