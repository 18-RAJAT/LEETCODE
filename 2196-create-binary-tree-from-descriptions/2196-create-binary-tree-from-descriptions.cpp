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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n=descriptions.size();
        unordered_map<int,vector<pair<int,int>>>ump;
        unordered_map<int,int>value;
        if(n==0)
        {
            return NULL;
        }
        int p=descriptions[0][0];
        set<int>v;
        for(int i=0;i<n;++i)
        {
            ump[descriptions[i][0]].push_back({descriptions[i][1],descriptions[i][2]});
            value[descriptions[i][1]]++;
            if(descriptions[i][1]==p)
            {
                p=descriptions[i][0];
            }
            value[descriptions[i][1]]=descriptions[i][0];
        }
        while(value[p]!=0)
        {
            p=value[p];
        }
        queue<TreeNode*> q;
        q.push(new TreeNode(p));
        TreeNode* F=q.front();
        while(!q.empty())
        {
            auto t=q.front();
            q.pop();
            if(ump.find(t->val)!=ump.end())
            {
                vector<pair<int,int>> v1=ump[t->val];
                for(int j=0;j<v1.size();++j)
                {
                    if(v1[j].second==0)
                    {
                        q.push(new TreeNode(v1[j].first));
                        t->right=q.back();
                        
                    }
                    else
                    {
                        q.push(new TreeNode(v1[j].first));
                        t->left=q.back();
                    }
                }
            }
        }
        return F;
    }
};