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
    vector<int>BinaryTree;
    void inorder(TreeNode*root)
    {
        if(!root){return;}
        inorder(root->left);
        BinaryTree.push_back(root->val);
        inorder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        if(!root)return true;
        if(!root->right and !root->left)return true;
        inorder(root);
        int n=BinaryTree.size()-1;
        for(int i=0;i<n;++i)
            if(BinaryTree[i]>=BinaryTree[i+1])return false;
        return true;
    }
};

//r->l
//bt.pb->(r->v)
//r->r