// the algorithm is like before, but use pointer to pass vector<TreeNode*>, to save cost on copy constructor

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
    vector<TreeNode*> * generateTrees(int start, int end)
    {
        vector<TreeNode*> * res = new vector<TreeNode*>; 
        if(start>end) 
        {
            res->push_back(NULL);
        }
        else
        {
            int i = start; 
            while(i<=end)
            {
                vector<TreeNode*> * left = generateTrees(start,i-1);
                vector<TreeNode*> * right = generateTrees(i+1,end);
                for(int j=0;j<left->size();j++)
                    for(int k=0;k<right->size();k++)
                    {
                        TreeNode* root = new TreeNode(i); 
                        root->left = (*left)[j];
                        root->right = (*right)[k];
                        res->push_back(root);
                    }
                delete left;
                delete right;
                i++; 
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*>* res = generateTrees(1,n);            
        return *res;
    }
};
