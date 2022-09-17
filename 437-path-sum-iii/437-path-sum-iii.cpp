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
//     int pathSum(TreeNode* root, int targetSum) {
//         if(root==nullptr)return 0;
//         return solve(root,targetSum)+pathSum(root->left,targetSum)+pathSum(root->right,targetSum);
//     }
    
//     int solve(TreeNode*root,int targetSum)
//     {
//         if(root==nullptr){return 0;}
//         return(targetSum==root->val)+solve(root->left,targetSum-root->val)+solve(root->right,targetSum-root->val);
//     }
    
    
    
    
//         int pathSum(TreeNode* root, int targetSum) {
//             return root?solve(root,targetSum)+pathSum(root->left,targetSum)+pathSum(root->right,targetSum):0;
//         }
        
//         int solve(TreeNode* root,int targetSum)
//         {
//             return root?solve(root,targetSum)+solve(root->left,targetSum-root->val)+solve(root->right,targetSum-root->val):0;
//         }
    // int answer=0;
        
        int pathSum(TreeNode* root, int targetSum) {
            if(root==nullptr){return 0;}
            // targetSum=targetSum+(root->val);
            return pathSum(root->left,targetSum)+pathSum(root->right,targetSum)+dfs(root,targetSum);
        }
        int dfs(TreeNode*root,long long targetSum)
        {
            if(root==nullptr){return 0;}
            long long count=0;
            if(root->val==targetSum){count++;}
            
            count+=dfs(root->left,targetSum-root->val);
            count+=dfs(root->right,targetSum-root->val);
            
            return count;
        }
};