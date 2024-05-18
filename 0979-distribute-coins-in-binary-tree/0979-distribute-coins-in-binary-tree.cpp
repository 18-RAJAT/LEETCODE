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
    int recur(TreeNode* r, int& steps){
        if(r==NULL) return 0;
        int c1=recur(r->left,steps);
        int c2=recur(r->right,steps);
        steps+=abs(c1)+abs(c2);
        return c1+c2+(r->val-1);
    }

    int distributeCoins(TreeNode* root) {
        int steps=0;
        recur(root,steps);
        return steps;
    }
};