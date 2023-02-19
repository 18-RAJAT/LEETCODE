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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        auto cmp=[](TreeNode*a,TreeNode*b)
        {
            return a->val>b->val;
        };
        function<void(TreeNode*,int)>dfs=[&](TreeNode*node,int lvl)
        {
            if(not root)
            {
                return;
            }
            if(lvl>=ans.size())
            {
                ans.push_back({});
            }
            if(lvl%2==0)
            {
                ans[lvl].push_back(node->val);
            }
            else
            {
                ans[lvl].insert(ans[lvl].begin(),node->val);
            }
            if(node->left)
            {
                dfs(node->left,lvl+1);
            }
            if(node->right)
            {
                dfs(node->right,lvl+1);
            }
        };
        dfs(root,0);
        return ans;
    }
    private:
    vector<vector<int>>ans;
};