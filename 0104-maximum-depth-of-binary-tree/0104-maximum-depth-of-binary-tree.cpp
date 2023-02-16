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
    int maxDepth(TreeNode* root) {
        function<int(TreeNode*)>dfs=[&](TreeNode* root)->int
        {
            if(root==nullptr){return 0;}
            return 1+max(dfs(root->left),dfs(root->right));
        };
        return dfs(root);
    }
};