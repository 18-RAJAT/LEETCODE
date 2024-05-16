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
    bool dfs(TreeNode* root)
    {
        if(root->left==0 || root->right==0)
        {
            return root->val;
        }
        else
        {
            if(root->val==2)
            {
                return dfs(root->right)|dfs(root->left);
            }
            else
            {
                return dfs(root->right)&dfs(root->left);
            }
        }
        return true;
    }
    bool evaluateTree(TreeNode* root) {
        return dfs(root);
    }
};