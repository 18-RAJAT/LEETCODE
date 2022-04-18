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
    int counter=0,answer=0;
    int kthSmallest(TreeNode* root, int k) {
          
        //inorder traversal
        if(!root)
        {
            return answer;
        }
        
        kthSmallest(root->left,k);
        
               counter++;
        
        if(counter==k)
            
            answer=root->val;
        
            kthSmallest(root->right,k);
        
        
        return answer;
        
    }
};