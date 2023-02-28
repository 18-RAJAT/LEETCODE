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
    vector<TreeNode*>chk;
    map<string,int>mp;
    string sol(TreeNode*root)
    {
        if(not root)
        {
            return "";
        }
        string left='l'+sol(root->left);
        string right='r'+sol(root->right);
        
        string s=left+to_string(root->val)+right;
        
        if(mp[s]==1)
        {
            chk.push_back(root);
        }
        mp[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        sol(root);
        return chk;
    }
};