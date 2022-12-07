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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==nullptr)
        {
            return 0;
        }
        // return rangeSumBST(root+1,low+1,high+1);
        if(root->val>=low and root->val<=high)
        {
            return root->val+rangeSumBST(root->right,low,high)+rangeSumBST(root->left,low,high);
        }
        else if(root->val<low)
            
           return rangeSumBST(root->right,low,high);
            
        else
            
           return rangeSumBST(root->left,low,high);
    }
};