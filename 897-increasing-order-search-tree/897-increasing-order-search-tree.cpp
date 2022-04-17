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
    TreeNode* increasingBST(TreeNode* root) {
        
        if(root == NULL)
        {
            return NULL;
        }
        
        if(root->left == NULL)
        {
          root->right = increasingBST (root->right);
            {
                return root;
            }
        }
        
        //Swapping....
        TreeNode* node = root->left;
        root->left = node->right;
        node->right = root;
        
        return increasingBST(node);
        
    }
};