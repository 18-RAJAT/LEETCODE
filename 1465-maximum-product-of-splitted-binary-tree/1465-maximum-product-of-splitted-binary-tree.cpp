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
    int recur(TreeNode* root,vector<int>& res)
    {
        if(root==nullptr)return 0;
        int l=recur(root->left,res);
        int r=recur(root->right,res);
        int sum=root->val+l+r;
        res.push_back(sum);
        return sum;
    }
    int maxProduct(TreeNode* root) {
        long long ans=0;
        vector<int>res;
        //first call to get total tree sum and fill all subtree sums
        int tot=recur(root,res);
        //try all splits: product = subtreeSum * (total - subtreeSum)
        for(auto& it:res)ans=max(ans,(long long)it*(tot-it));
        return ans%1000000007;
    }
};