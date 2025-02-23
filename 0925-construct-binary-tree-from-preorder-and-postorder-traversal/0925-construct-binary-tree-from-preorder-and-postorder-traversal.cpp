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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int,int> pos;
        for(int i=0;i<postorder.size();++i)pos[postorder[i]]=i;
        int idx=0;
        return construct(preorder,postorder,pos,idx,0,preorder.size()-1);
    }
    TreeNode* construct(vector<int>& pre,vector<int>& post,unordered_map<int,int>& pos,int& idx,int l,int r)
    {
        if(idx>=pre.size() || l>r) return nullptr;
        
        TreeNode* root=new TreeNode(pre[idx++]);
        if(idx<pre.size() && l<=r)
        {
            int mid=pos[pre[idx]];
            if(mid<=r)root->left=construct(pre,post,pos,idx,l,mid);
            if(mid+1<=r-1)root->right=construct(pre,post,pos,idx,mid+1,r-1);
        }
        return root;
    }
};