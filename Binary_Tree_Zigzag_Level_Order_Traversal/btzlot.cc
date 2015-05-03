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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        typedef vector<int> IntVec;
        typedef vector<IntVec> IntVecVec;
        typedef TreeNode Node;
        typedef queue<Node*> Queue;
        IntVecVec res;
        if(root==NULL) return res;
        Queue q;
        q.push(root);
        bool do_reverse=false;

        while(!q.empty())
        {
            int count = q.size(); 
            IntVec v;
            while(count>0)
            {
                Node* cur = q.front();
                q.pop();
                v.push_back(cur->val); 
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
                count--; 
            }

            if(do_reverse)
            {
                reverse(v.begin(), v.end()); 
                do_reverse=false;
            }
            else
                do_reverse=true;

            res.push_back(v);
        }

        return res;
    }
};
