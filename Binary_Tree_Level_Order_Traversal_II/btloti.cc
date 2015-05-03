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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        if(root == NULL)        
            return res;

        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            res.push_back(vector<int>());
            int count = q.size(); 
            while(count>0)
            {
                TreeNode* cur = q.front(); 
                q.pop();
                res.back().push_back(cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
                count--;
            }
        }

        reverse(res.begin(),res.end());
        return res;
    }
};
