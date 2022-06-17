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
        int ct=0;
    int minCameraCover(TreeNode* root) {
            // int ct=0;
            if(dfs(root)==-1){ct++;}return ct;
    }
        int dfs(TreeNode* root)
        {
                // int ct=0;
                if(root==NULL){return 1;}
                int left=dfs(root->left);//cout<<"L";
                int right=dfs(root->right);//cout<<"R";
                
                 //Case 1
                if(left==-1 or right==-1){ct++;return 0;}
                //case 2
                if(left==0 or right==0){return 1;}
                return -1;
        }
};
