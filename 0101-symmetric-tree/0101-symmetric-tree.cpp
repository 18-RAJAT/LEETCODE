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
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)
        {
            return true;
        }
        return isMirror(root->left,root->right);
    }
    bool isMirror(TreeNode* root1,TreeNode* root2)
    {
        if(root1==nullptr and root2==nullptr)
        {
            return true;
        }
        if(root1==nullptr or root2==nullptr)
        {
            return false;
        }
        return (root1->val==root2->val) and isMirror(root1->left,root2->right) and isMirror(root1->right,root2->left);
    }
};