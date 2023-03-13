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
    TreeNode* balanceBST(TreeNode* root) {
        function<void(TreeNode*,vector<int>&)>inorder=[&](TreeNode*node,vector<int>&db)->void
        {
            if(node==nullptr)
            {
                return;
            }
            inorder(node->left,db);
            db.push_back(node->val);
            inorder(node->right,db);
        };
        
        function<TreeNode*(int,int,const vector<int>&)>buildBST=[&](int start,int end,const vector<int>&db)->TreeNode*
        {
            if(start>end)
            {
                // return nullptr;
                return static_cast<TreeNode*>(nullptr);
            }
            int mid=start+(end-start)/2;
            TreeNode*root=new TreeNode(db[mid]);
            root->left=buildBST(start,mid-1,db);
            root->right=buildBST(mid+1,end,db);
            return root;
        };
        
        //build in trav
        vector<int>INORDER;
        inorder(root,INORDER);
        
        //in arr build BST(balance)
        return buildBST(0,size(INORDER)-1,INORDER);
        
    }
};
