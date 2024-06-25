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
    int recur(TreeNode* root,int sum)
    {
        if(!root)return 0;
        int r=recur(root->right,sum);
        int value=root->val;
        root->val+=sum+r;
        int l=recur(root->left,root->val);
        return l+r+value;
    }
    TreeNode* bstToGst(TreeNode* root) {
        recur(root,0);
        return root;
    }
};