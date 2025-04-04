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
class Solution{
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root,maxDepth(root),0LL);
    }
    TreeNode* dfs(TreeNode* root,int mx,int x)
    {
        if(!root)return NULL;
        if(x==mx-1)return root;
        TreeNode* l=dfs(root->left,mx,x+1),*r=dfs(root->right,mx,x+1);
        if(l && r)return root;
        return l?l:r;
    }
    int maxDepth(TreeNode* root)
    {
        if(!root)return 0;
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
};