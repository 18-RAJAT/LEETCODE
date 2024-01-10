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
    unordered_map<int,pair<int,int>>mp;
    int sol(TreeNode *root)
    {
        if(!root)
        {
            return 0;
        }
        int l=sol(root->left);
        int r=sol(root->right);
        mp[root->val]={l,r};
        return max(l,r)+1;
    }
    void check(TreeNode *root,int val,int &res,int start)
    {
        if(!root)
        {
            return;
        }
        int l=mp[root->val].first;
        int r=mp[root->val].second;
        if(root->val==start)
        {
            res=max(l,max(r,val));
        }
        check(root->left,1+max(val,r),res,start);
        check(root->right,1+max(val,l),res,start);
    }
    int amountOfTime(TreeNode* root, int start) {
        mp.clear();
        int res=0;
        int h=sol(root);
        check(root,0,res,start);
        return res;
    }
};