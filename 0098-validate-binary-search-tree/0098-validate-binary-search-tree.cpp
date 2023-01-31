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
    bool isValidBST(TreeNode* root,long long mx=LONG_MAX,long long mn=LONG_MIN) {
        /*
            BST,each node has a value and two children,one smaller and one larger
            so that all values in the left subtree are less than the node and all 
            values in the right subtree are greater than the node.
        */
        if(root==nullptr)
        {
            return true;
        }
        if(root->val>=mx or root->val<=mn)
        {
            return false;
        }
        // if(root->right!=nullptr and root->right->val<=root->val)
        // {
        //     return false;
        // }
        return isValidBST(root->left,root->val,mn) and isValidBST(root->right,mx,root->val);
    }
};
/*
    Time complexity: O(n), where n is the number of nodes in the binary search tree.
    This is because the function visits each node once in the worst case.

    Space complexity: O(h), where h is the height of the binary search tree. 
    This is because the function uses the call stack to store the function calls, 
    and the height of the binary search tree determines the maximum depth of the call stack.

*/