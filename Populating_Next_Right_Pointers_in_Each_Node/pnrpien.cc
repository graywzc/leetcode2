/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
// recursive way
class Solution {
public:
    void connect(TreeLinkNode *root) {
        typedef TreeLinkNode Node;
        if(root==NULL)
            return;
        else
        {
            Node* left = root->left;     
            Node* right = root->right;
            while(left)
            {
                assert(right);
                left->next = right; 
                left = left->right;
                right = right->left;
            }

            connect(root->left);
            connect(root->right);
        }
    }
};
