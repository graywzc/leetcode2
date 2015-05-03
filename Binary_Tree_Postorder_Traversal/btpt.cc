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
    vector<int> postorderTraversal(TreeNode *root) {
        typedef TreeNode Node;
        stack<Node*> st;
        Node *cur = root;
        Node *prev = NULL;
        vector<int> res;

        while(cur || !st.empty())
        {
            if(cur) 
            {
                st.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = st.top();
                if(cur->right==NULL || cur->right==prev)
                {
                    // do 
                    res.push_back(cur->val); 

                    prev = cur;
                    cur = NULL;
                    st.pop();
                }
                else
                {
                    cur = cur->right;        
                }
            }
        }
        return res;
    }
};
