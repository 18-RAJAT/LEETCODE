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
    int recur(TreeNode* root,unordered_map<TreeNode*,int>& mp)
    {
        if(root==nullptr)return 0;
        if(mp.count(root))return mp[root];
        int ans=root->val;
        if(root->left)
        {
            ans+=recur(root->left->left,mp)+recur(root->left->right,mp);
        }
        if(root->right)
        {
            ans+=recur(root->right->left,mp)+recur(root->right->right,mp);
        }
        ans=max(ans,recur(root->left,mp)+recur(root->right,mp));
        return mp[root]=ans;
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int>mp;
        return recur(root,mp);
    }
};