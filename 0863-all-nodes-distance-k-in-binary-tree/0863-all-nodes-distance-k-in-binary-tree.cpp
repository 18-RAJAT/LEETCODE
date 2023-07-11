/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void kdown(TreeNode* root, int k, TreeNode* blockNode, vector<int> &ans){
        if(root == NULL or k < 0 or root == blockNode) return;
        if(k == 0){
            ans.push_back(root->val);
            return;
        }
        kdown(root->left,k-1,blockNode,ans);
        kdown(root->right,k-1,blockNode,ans);
        
    }
    int distanceKk(TreeNode* root,TreeNode* target,int k,vector<int>&ans){
        if(root == NULL) return -1;
        if(root == target){
            kdown(root,k-0,NULL,ans);
            return 1;
        }
        int ld = distanceKk(root->left,target,k,ans);
        if(ld != -1){
            kdown(root,k-ld,root->left,ans);
            return ld + 1;
        }
        
        int rd = distanceKk(root->right,target,k,ans);
        if(rd != -1){
            kdown(root,k-rd,root->right,ans);
            return rd + 1;
        }
        return -1; 
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        distanceKk(root,target,k,ans);
        return ans;
    }
};