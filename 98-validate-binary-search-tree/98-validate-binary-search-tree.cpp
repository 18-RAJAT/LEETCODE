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
    vector<int>bTree;
    void inorder(TreeNode* root)
    {
        if(root==nullptr)
        {
            return;
        }
        inorder(root->left);
        bTree.push_back(root->val);
        inorder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        
        if(root->right==nullptr and root->left==nullptr)
        {
            return true;
        }
        inorder(root);
        int n=bTree.size()-1;
        for(int i=0;i<n;++i)
        {
            if(bTree[i+1]<=bTree[i])
            {
                return false;
            }
        }
        return true;
    }
};