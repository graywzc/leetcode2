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
    vector<int> inorderTraversal(TreeNode *root) {
        typedef TreeNode Node;
        Node* cur = root;
        stack<Node*> st;
        vector<int> res;
        
        while(cur || !st.empty())
        {
            if(cur==NULL)    
            {
                cur = st.top(); 
                st.pop();
                // do
                res.push_back(cur->val);
                cur = cur->right;
            }
            else
            {
                st.push(cur); 
                cur = cur->left;
            }
        }

        return res;
    }
};
