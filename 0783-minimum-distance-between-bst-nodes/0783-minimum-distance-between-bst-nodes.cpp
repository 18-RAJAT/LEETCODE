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
    int minDiffInBST(TreeNode* root) {
        function<void(TreeNode*)>inorder=[&](TreeNode* root)
        {
            if(root==nullptr)
            {
                return;
            }
            inorder(root->left);
            if(prev!=nullptr)
            {
                ans=min(abs(root->val-prev->val),ans);
            }
            prev=root;
            inorder(root->right);
        };
        inorder(root);
        return ans;
    }
    private:
    TreeNode*prev=nullptr;
    int ans=INT_MAX;
};