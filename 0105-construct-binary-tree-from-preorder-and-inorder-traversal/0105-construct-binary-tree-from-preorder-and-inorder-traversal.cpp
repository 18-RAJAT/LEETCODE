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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        if(n==0)
        {
            return NULL;
        }
        function<TreeNode*(int,int,int,int)>dfs=[&](int l1,int r1,int l2,int r2)->TreeNode*
        {
            if(l1>r1)
            {
                return NULL;
            }
            TreeNode* root=new TreeNode(preorder[l1]);
            int pos=l2;
            while(pos<=r2 && inorder[pos]!=preorder[l1])
            {
                pos++;
            }
            root->left=dfs(l1+1,l1+pos-l2,l2,pos-1);
            root->right=dfs(l1+pos-l2+1,r1,pos+1,r2);
            return root;
        };
        return dfs(0,n-1,0,n-1);
    }
};