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
    vector<int> findMode(TreeNode* root) {
        TreeNode* curr=root;
        vector<int>ans;
        int maxi=0;
        int prev=-1;
        int cnt=0;
        function<void(TreeNode*)>dfs=[&](TreeNode* curr)->void
        {
            if(curr==nullptr)
            {
                return;
            }
            dfs(curr->left);
            if(prev==-1)
            {
                prev=curr->val;
                cnt=1;
            }
            else if(prev==curr->val)
            {
                cnt++;
            }
            else
            {
                cnt=1;
                prev=curr->val;
            }
            if(cnt==maxi)
            {
                ans.push_back(curr->val);
            }
            else if(cnt>maxi)
            {
                ans.clear();
                ans.push_back(curr->val);
                maxi=cnt;
            }
            dfs(curr->right);
        };
        dfs(curr);
        return ans;
    }
};