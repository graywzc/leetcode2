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
    vector<int> reverseRSV(TreeNode *node)
    {
        assert(node);
        if(node->left==NULL && node->right==NULL) 
        {
            vector<int> res(1,node->val); 
            return res;
        }
        else if(node->left==NULL)
        {
            vector<int> res = reverseRSV(node->right); 
            res.push_back(node->val);
            return res;
        }
        else if(node->right==NULL)
        {
            vector<int> res = reverseRSV(node->left); 
            res.push_back(node->val);
            return res;
        }
        else
        {
            vector<int> lres = reverseRSV(node->left); 
            vector<int> rres = reverseRSV(node->right); 
            if(lres.size()<=rres.size())
            {
                rres.push_back(node->val); 
                return rres;
            }
            else
            {
                copy(rres.begin(), rres.end(), lres.begin() + (lres.size()-rres.size())); 
                lres.push_back(node->val);
                return lres;
            }
        }
    }

    vector<int> rightSideView(TreeNode *root) {
        if(root==NULL)
            return vector<int>();
        else
        {
            vector<int> res = reverseRSV(root);
            reverse(res.begin(), res.end());
            return res;
        }
    }
        
};
