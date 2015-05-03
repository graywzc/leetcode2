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
    void ps(TreeNode* nd, vector<int>& temp, vector<vector<int>>& res, int sum)
    {
        if(nd->left == NULL && nd->right == NULL)  
        {
            if(sum == nd->val) 
            {
                temp.push_back(sum); 
                res.push_back(temp);
                temp.pop_back();
            }
        }
        temp.push_back(nd->val);
        if(nd->left != NULL)
            ps(nd->left,temp,res,sum-nd->val); 
        if(nd->right != NULL)
            ps(nd->right, temp, res, sum-nd->val);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if(root==NULL)
            return res;

        vector<int> temp;
        ps(root, temp, res, sum);
        return res;
    }
};
