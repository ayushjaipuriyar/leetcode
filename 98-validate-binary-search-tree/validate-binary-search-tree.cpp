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
    // bool isBST(TreeNode* root,int min,int max){
    //     if(root==NULL)
    //         return 1;
    //     if(root->val < min || root->val > max)
    //         return 0;
    //     return (isBST(root->left,min,root->val-1)&&isBST(root->right,root->val-1,max));
    // }
    // bool isValidBST(TreeNode* root) {
    //     return isBST(root,INT_MIN,INT_MAX);
    // }
    bool isValidBST(TreeNode* root, TreeNode* l=NULL, TreeNode* r=NULL)
{
    if (root == NULL)
        return true;
    if (l != NULL and root->val <= l->val)
        return false;

    if (r != NULL and root->val >= r->val)
        return false;
 
    return isValidBST(root->left, l, root) and
           isValidBST(root->right, root, r);
}

};