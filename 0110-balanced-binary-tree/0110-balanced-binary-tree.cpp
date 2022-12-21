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
    bool check;
    int dfs(TreeNode* root)
    {
        if(!root)
        {
            return false;
        }
        if(!check)
        {
            return false;
        }
        int leftSub=dfs(root->left);
        int rightSub=dfs(root->right);
        
        if(abs(leftSub-rightSub)>1)
        {
            check=false;
        }
        return 1+max(leftSub,rightSub);
    }
    bool isBalanced(TreeNode* root) {
        check=true;
        // if(root==nullptr)
        // {
        //     return nullptr;
        // }
        // return isBalanced(root);    
        int a=dfs(root);
        return check;
    }
};