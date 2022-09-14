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
    int arr[1001]={},ans=0;
    void dfs(TreeNode *root) {
        if(root==nullptr){return;}
        arr[root->val]++;
        if(root->left==nullptr and root->right==nullptr)
        {
            int c=0;
            for(int i=1;i<1001;++i) 
            {
                c+=arr[i]%2;
                if(c>=2)break;
            }
            if(c<2)ans++;
        }
        dfs(root->left);
        dfs(root->right);
        arr[root->val]--;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root);return ans;
    }
};