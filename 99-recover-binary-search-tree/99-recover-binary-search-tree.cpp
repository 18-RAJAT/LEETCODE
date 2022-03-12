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
    
    TreeNode* first = NULL, *second = NULL, *previous = NULL;
    
public:
    
    void Fix_Node(TreeNode* root)
    {
        if(root == NULL)
        {
            return;
        }
        
        Fix_Node(root->left);
        
        if(previous and root->val < previous->val)
        {
            if(first == NULL)
            {
                first = previous;
            }
            second = root;
        }
        
        previous = root;
        
        Fix_Node(root->right);
    }
    
    
    void recoverTree(TreeNode* root) {
        
        Fix_Node(root);
        
        swap(first->val,second->val);
        
    }
};