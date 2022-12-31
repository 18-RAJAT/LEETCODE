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
    bool isUnivalTree(TreeNode* root) {
        if(root==nullptr)
        {
            return true;
        }
        if(root->left!=nullptr and root->left->val!=root->val or root->right!=nullptr and root->right->val!=root->val)
        {
            return false;
        }
        return isUnivalTree(root->left) and isUnivalTree(root->right);
    }
};