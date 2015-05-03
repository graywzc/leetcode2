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

    vector<int> preorderTraversal(TreeNode *root) {
        typedef TreeNode Node;
        stack<Node*> st;
        vector<int> res;
        Node *cur = root;

        while(cur || !st.empty())
        {
            if(cur) 
            {
                //do
                res.push_back(cur->val);

                st.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = st.top()->right;
                st.pop();
            }
        }

        return res;
    }
};
