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
private:
    int dfs(TreeNode* root, vector<int> &res) {
        if (!root) return 0;
        int sum = root->val + dfs(root->left, res) + dfs(root->right, res);
        res.push_back(sum);
        return sum;
    }
public:
    int maxProduct(TreeNode* root) {
        vector<int> bottomUpValues;
        dfs(root, bottomUpValues);
        int sum = bottomUpValues.back();
        long res = INT_MIN, mod = 1e9+7;
        for (int i = 0; i < bottomUpValues.size()-1;++i) 
        {
            res = max(res, (long)bottomUpValues[i] * (sum-bottomUpValues[i]));
        }
        return res % mod;
    }
};