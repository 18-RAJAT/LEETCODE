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
    int longestZigZag(TreeNode* root) {
        int ZigZag=0;
        function<void(TreeNode*,int,int)>dfs=[&](TreeNode* root,int l,int r)->void
        {
            if(not root)
            {
                return;
            }
            ZigZag=max(ZigZag,max(l,r));
            
            dfs(root->left,0,l+1);
            dfs(root->right,r+1,0);
            
            return;
        };
        dfs(root,0,0);
        return ZigZag;
    }
};