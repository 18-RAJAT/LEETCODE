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
    vector<TreeNode*> delNodes(TreeNode* root,vector<int>& to_delete)
    {
        vector<TreeNode*>ans;
        delete_node(root,to_delete,ans);
        if(root)ans.push_back(root);
        return ans;
    }
    void delete_node(TreeNode* &root, vector<int>& to_delete, vector<TreeNode*> &ans){
        if(root==nullptr)return;
        delete_node(root->right,to_delete,ans);
        delete_node(root->left,to_delete,ans);
        if(find(to_delete.begin(),to_delete.end(),root->val)!=to_delete.end())
        {
            if(root->left)ans.push_back(root->left);
            if(root->right)ans.push_back(root->right);
            root = nullptr;
      }
    }
};