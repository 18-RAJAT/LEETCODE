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
    int recur(TreeNode* root,int& res)
    {
        if(root==nullptr)return 0;
        int l=recur(root->left,res),r=recur(root->right,res);
        //height of the current node.
        int height=1+max(l,r);
        //path passing current node.
        int ans=max(height,1+l+r);
        res=max(res,ans);
        //parent node.
        return height;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        recur(root,ans);
        /*
            edges=node-1...
            Longest path = 2 -> 1 -> 3

            Nodes=3 ->> [2, 1, 3],Edges=2, ans=Nodes-1...
        */
        return ans-1;
    }
};