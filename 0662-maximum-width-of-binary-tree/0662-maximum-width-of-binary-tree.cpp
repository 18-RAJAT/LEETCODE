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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        int res=0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            int size=q.size();
            int first=q.front().second;
            int last=q.back().second;    
            for(int i=0;i<size;++i)
            {
                auto it=q.front();
                q.pop();
                int cur=it.second-last;
                TreeNode* t=it.first;
                if(i==0) first=cur;
                if(i==size-1) last=cur;
                if(t->left) q.push({t->left,2*cur+1});
                if(t->right) q.push({t->right,2*cur+2});
            }
            res=max(res,last-first+1);
        }

        return res;
    }
};