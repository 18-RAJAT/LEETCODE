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
    
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        
        if(root == NULL)
        {
            return root;
        }
        
        TreeNode* leftSide = trimBST(root->left,low,high); //Output from left subtree
        TreeNode* rightSide = trimBST(root->right,low,high); //Output from right subtree
        
        int rootValue = root->val;
        
       //If rootvalue is less than low we discard root and it's left subtree as will be less and return right subtree
        if(rootValue < low)
        {
            return rightSide;
        }
      //If rootvalue is greater than high we discard right subtree as will be return left subtree
        if(rootValue > high)
        {
            return leftSide;
        }
        
        //If root is within the limit and then we will be join the right and left sutree with root and return
        
        root->left = leftSide;
        root->right = rightSide;
        
        return root;
    }
};