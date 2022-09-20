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
//     void bfs(TreeNode*root,int value,int maximum)
//     {
//         if(root==nullptr){return nullptr;}
//         if(root->left!=nullptr and root->right!=nullptr)
        
//     }
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        
        if(root==nullptr){return ans;}
        queue<TreeNode*>q;
        
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            int maximum=INT_MIN;
            while(size--)
            {
                TreeNode*temp=q.front();q.pop();
                maximum=max(temp->val,maximum);
                
                if(temp->left){q.push(temp->left);}
                if(temp->right){q.push(temp->right);}
            }
            ans.push_back(maximum);
        }
        return ans;
    }
};