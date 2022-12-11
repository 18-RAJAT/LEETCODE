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
    int solve(TreeNode*root,int& maximumSum)
    {
        if(root==nullptr)
        {
            return 0;
        }
        int leftChild=max(solve(root->left,maximumSum),0);
        int rightChild=max(solve(root->right,maximumSum),0);
        
        maximumSum=max(maximumSum,root->val+leftChild+rightChild);
        return root->val+max(leftChild,rightChild);
    }
    int maxPathSum(TreeNode* root) {
        int maximumSum=INT_MIN;
        
        solve(root,maximumSum);
        return maximumSum;
    }
};