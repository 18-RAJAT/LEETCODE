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
    int tiltSum = 0;
    
    int findTilt(TreeNode* root) {
        
        dfs(root);
        return tiltSum;
    }
    
    int dfs(TreeNode* root)
    {
        if(!root)
        {
        return 0;
        }
        
        int leftsum = dfs(root->left);
        int rightsum  = dfs(root->right);
            
        tiltSum += abs(leftsum - rightsum);
        
        return leftsum + rightsum + root->val;
    }
};