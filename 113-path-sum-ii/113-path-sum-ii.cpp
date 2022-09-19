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
    // vector<vector<int>>result;
    // void dfs(TreeNode* node,vector<int>temp,int targetSum)
    // {
    //     if(node==nullptr)return;
    //     temp.push_back(node->val);
    //     targetSum-=node->val;
    //     if(targetSum==0 and node->left==nullptr and node->right==nullptr)
    //     {
    //         result.push_back(temp);
    //         return;
    //     }
    //     dfs(node->left,temp,targetSum);
    //     dfs(node->right,temp,targetSum);
    // }
void helper(TreeNode* root,int targetSum,vector<int>v,vector<vector<int>>&result)
{
    if(root==nullptr){return;}
    v.push_back(root->val);
    if(root->left==nullptr and root->right==nullptr and root->val==targetSum)
    {
        result.push_back(v);
    }
    helper(root->left,targetSum-root->val,v,result);
    helper(root->right,targetSum-root->val,v,result);
    
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        // vector<int>temp;
        // dfs(root,temp,targetSum);
        // return result;
        vector<int>v;
        vector<vector<int>>result;
        helper(root,targetSum,v,result);
        return result;
    }
};