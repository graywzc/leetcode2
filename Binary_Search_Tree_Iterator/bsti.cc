#include <iostream>
#include <stack>
using namespace std;

/**
 * Definition for binary tree
 */
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class BSTIterator {
public:
    stack<TreeNode*> st;

    BSTIterator(TreeNode *root) {
        while(root)     
        {
            st.push(root); 
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();    
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* nd = st.top();    
        st.pop();
        int val = nd->val;
        nd = nd->right;
        while(nd)
        {
            st.push(nd);
            nd = nd->left;
        }
        return val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
int main()
{
    TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(-1);
    root->right = new TreeNode(1);

    BSTIterator j = BSTIterator(NULL);
    while(j.hasNext())
        cout<<j.next()<<endl;
    
    BSTIterator i = BSTIterator(root);
    while(i.hasNext())
        cout<<i.next()<<endl;
}
