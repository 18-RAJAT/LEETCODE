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
    TreeNode* recoverFromPreorder(string traversal) {
        stack<pair<TreeNode*,int>>stk;
        int i=0,n=traversal.size();
        while(i<n)
        {
            int depth=0;
            while(i<n && traversal[i]=='-')depth++,i++;
            int val=0;
            while(i<n && isdigit(traversal[i]))val=val*10+(traversal[i++]-'0');
            TreeNode* node=new TreeNode(val);
            while(!stk.empty() && stk.top().second>=depth)stk.pop();
            if(!stk.empty())
            {
                if(!stk.top().first->left)stk.top().first->left=node;
                else stk.top().first->right=node;
            }
            stk.push({node,depth});
        }
        while(stk.size()>1)stk.pop();
        return stk.top().first;
    }
};