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
    void dfs(TreeNode* root,int lvl,vector<int>&tp)
    {
        if(!root){return;}
        if(lvl==tp.size()){tp.push_back(root->val);}
        if(root->right){dfs(root->right,lvl+1,tp);}
        if(root->left){dfs(root->left,lvl+1,tp);}
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        dfs(root,0,res);
        return res;
    }
};