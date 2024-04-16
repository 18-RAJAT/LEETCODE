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
    TreeNode* Dfs(TreeNode* root,int val,int depth)
    {
        if(root==NULL)
        {
            return NULL;
        }
        if(depth==1)
        {
            TreeNode* left=new TreeNode(val,root->left,NULL);
            TreeNode* right=new TreeNode(val,NULL,root->right);
            return new TreeNode(root->val,left,right);
        }
        root->left=Dfs(root->left,val,depth-1);
        root->right=Dfs(root->right,val,depth-1);
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)return new TreeNode(val,root,NULL);
        return Dfs(root,val,depth-1);
    }
};