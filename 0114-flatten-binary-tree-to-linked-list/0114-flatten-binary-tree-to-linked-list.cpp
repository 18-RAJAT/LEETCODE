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
    TreeNode*previous=nullptr;
    void flatten(TreeNode* root) {
        // TreeNode*previous=nullptr;
        if(root==nullptr)
        {
            return;
        }
        
        flatten(root->right);
        flatten(root->left);
        
        root->right=previous;
        root->left=nullptr;
        previous=root;
    }
};