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
    int dfs(TreeNode* root,string s,string &ans)
    {
        if(!root)
        {
            return 0;
        }
        s=char('a'+root->val)+s;
        if(!root->left && !root->right)
        {
            if(ans=="")
            {
                ans=s;
            }
            else
            {
                ans=min(ans,s);
            }
        }
        dfs(root->left,s,ans);
        dfs(root->right,s,ans);
        return 0;
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans="";
        dfs(root,"",ans);
        return ans;
    }
};