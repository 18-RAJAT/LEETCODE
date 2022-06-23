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
    int help(TreeNode* root){
        if(root == NULL) return 0 ;
        int left = help(root->left);
        int right = help(root->right) ;
        if(left == -1 or right == -1 or abs(left - right) >1) return -1;
        return max(left,right) + 1;        
    }
    bool isBalanced(TreeNode* root) {
        return help(root) != -1;
    }
};