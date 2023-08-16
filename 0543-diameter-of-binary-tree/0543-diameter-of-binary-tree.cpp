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
    int maxi=0;
    //cache check
    int func(TreeNode* root)
    {
        if(root==nullptr)
        {
            return 0;
        }
        int L=func(root->left);
        int R=func(root->right);
        maxi=max<int>(L+R,maxi);
        
        return 1+max<int>(L,R);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        func(root);
        return maxi;
    }
};