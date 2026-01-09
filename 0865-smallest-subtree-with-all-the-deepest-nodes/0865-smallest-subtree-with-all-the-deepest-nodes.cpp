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
    pair<int,TreeNode*>dfs(TreeNode* root)
    {
        if(!root)return {0,NULL};
        auto l=dfs(root->left),r=dfs(root->right);
        if(r.first<l.first)return {l.first+1,l.second};
        if(l.first<r.first)return {r.first+1,r.second};
        return {l.first+1,root};
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }
};