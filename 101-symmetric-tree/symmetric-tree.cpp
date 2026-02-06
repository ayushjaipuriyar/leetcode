/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isMirror(TreeNode* x,TreeNode* y){
        if( x == NULL && y == NULL )
            return true;
        if( x && y && x->val == y->val)
            return (isMirror(x->left,y->right) && isMirror(x->right,y->left));
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return isMirror(root,root);
    }
};