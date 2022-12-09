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
    int ans=0;
    void solve(TreeNode* root,int parentmax,int parentmin)
    {
        if(root==nullptr)
        {
            return;
        }
        ans=max(ans,abs(parentmax-root->val));
        ans=max(ans,abs(parentmin-root->val));
        
        parentmax=max(parentmax,root->val);
        parentmin=min(parentmin,root->val);
        
        solve(root->left,parentmax,parentmin);
        solve(root->right,parentmax,parentmin);
        return;
    }
    int maxAncestorDiff(TreeNode* root) {
        
        solve(root,root->val,root->val);
//         int ans=0;
//         if(root==nullptr)
//         {
//             return false;
//         }
//         queue<TreeNode*>que;
//         que.push(root);
        
//         while(!que.empty())
//         {
//             TreeNode* tp=que.front();
//             que.pop();
//             int ans=0;
//             if(tp->left)
//             {
//                 que.push(tp->left);
//                 tp->left->val=max(tp->val,tp->left->val);
//                 tp->left->val=min(tp->val,tp->left->val);
//                 ans+=max(ans,abs(tp->val-tp->left->val));
//             }
            
//             if(tp->right)
//             {
//                 que.push(tp->right);
//                 tp->right->val=max(tp->val,tp->right->val);
//                 tp->right->val=min(tp->val,tp->right->val);
//                 ans+=max(ans,abs(tp->val-tp->right->val));
//             }
//         }
        return ans;
    }
};