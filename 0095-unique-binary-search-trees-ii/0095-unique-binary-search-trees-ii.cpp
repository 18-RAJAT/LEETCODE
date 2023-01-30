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
    vector<TreeNode*>solve(int start,int end)
    {
        vector<TreeNode*>a;
        if(start>end)
        {
            a.push_back(nullptr);
            return a;
        }
        if(start==end)
        {
            TreeNode*root=new TreeNode(start);
            root->left=nullptr;
            root->right=nullptr;
            a.push_back(root);
            return a;
        }
        for(int i=start;i<=end;++i)
        {
            auto L=solve(start,i-1);//left subtree which can be formed from 1 to i-1
            auto R=solve(i+1,end);//right subtree which can be formed from i+1 to n
            
            for(auto lSide:L)
            {
                for(auto rSide:R)
                {
                    TreeNode*root=new TreeNode(i);
                    root->left=lSide;
                    root->right=rSide;
                    a.push_back(root);
                }
            }
        }
        return a;
    }
    vector<TreeNode*>generateTrees(int n) {
        return solve(1,n);
    }
};