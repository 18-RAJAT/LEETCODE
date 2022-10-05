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
    TreeNode* dfs(TreeNode* root,int v,int dep)
    {
        if(root==nullptr)
        {
            return nullptr;
        }
        if(dep==1)
        {
            TreeNode* left = new TreeNode(v,root->left,nullptr);
            TreeNode* right = new TreeNode(v,nullptr,root->right);
            
            return new TreeNode(root->val,left,right);
        }
        
        TreeNode* l = dfs(root->left,v,dep-1);
        TreeNode* r = dfs(root->right,v,dep-1);
        
        return new TreeNode(root->val,l,r);
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
            return new TreeNode(val,root,nullptr);
        return dfs(root,val,depth-1);
    }
};