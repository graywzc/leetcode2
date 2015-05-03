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
    vector<vector<int> > levelOrder(TreeNode *root) {
        queue<TreeNode*> q;        
        vector<vector<int> > res;

        if(root==NULL)
            return res;

        q.push(root);
        while(!q.empty())
        {
            int count = q.size();  
            res.push_back(vector<int>());
            while(count>0)
            {
                TreeNode *cur = q.front();
                q.pop();
                res.back().push_back(cur->val);
                
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
                
                count--; 
            }
        }

        return res;
    }
};
