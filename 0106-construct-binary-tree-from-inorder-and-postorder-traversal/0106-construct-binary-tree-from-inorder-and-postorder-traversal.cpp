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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int m=postorder.size();
        if(n==0)
        {
            return NULL;
        }
        TreeNode*root=new TreeNode(postorder[m-1]);
        int i;
        for(i=0;i<n;i++)
        {
            if(inorder[i]==postorder[m-1])
            {
                break;
            }
        }
        vector<int>inleft(inorder.begin(),inorder.begin()+i);
        vector<int>inright(inorder.begin()+i+1,inorder.end());
        vector<int>postleft(postorder.begin(),postorder.begin()+i);
        vector<int>postright(postorder.begin()+i,postorder.end()-1);
        root->left=buildTree(inleft,postleft);
        root->right=buildTree(inright,postright);
        return root;
    }
};