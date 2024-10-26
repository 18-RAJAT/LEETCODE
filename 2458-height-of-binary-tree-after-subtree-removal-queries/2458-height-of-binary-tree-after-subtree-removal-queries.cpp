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
    unordered_map<int,pair<int,int>>high,lvl;
    int dfs(TreeNode* node,int depth=0)
    {
        if(node==nullptr)return -1;
        int L=dfs(node->left,depth+1);
        int R=dfs(node->right,depth+1);
        int h=max(L,R)+1;
        if(lvl.find(depth)==lvl.end())
        {
            lvl[depth]={h,-1};
        }
        else if(lvl[depth].first<h)
        {
            lvl[depth].second=lvl[depth].first;
            lvl[depth].first=h;
        }
        else if(lvl[depth].second<h)
        {
            lvl[depth].second=h;
        }
        high[node->val]={depth,h};
        return h;
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries)
    {
        dfs(root);
        vector<int>res;
        for(auto& it:queries)
        {
            int l=high[it].first;
            int h=high[it].second;
            pair<int,int>bestHeights=lvl[l];
            if(bestHeights.first==h)
            {
                res.push_back(l+bestHeights.second);
            }
            else
            {
                res.push_back(l+bestHeights.first);
            }
        }
        return res;
    }
};