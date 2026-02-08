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
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        int left_height = get_height(root->left);
        int right_height = get_height(root->right);
        if(abs(left_height - right_height) > 1)
            return false;
        return (isBalanced(root->left) && isBalanced(root->right));
    }
    int get_height(TreeNode* node){
        if (!node)
            return 0;
        int left_height = get_height(node->left);
        int right_height = get_height(node->right);
        return max(left_height, right_height)+1;

    }
};