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
    
    void solve(TreeNode* &root , int & current)
    {
        if(root == NULL)
        {
            return;
        }
        solve(root->right,current);
        root->val += current;
        
        current = root->val;
        solve(root->left,current);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        
        if(root == NULL)
        {
            return root;
        }
        
        int current = 0;
        solve(root,current);
        
       return root;
        
    }
};
