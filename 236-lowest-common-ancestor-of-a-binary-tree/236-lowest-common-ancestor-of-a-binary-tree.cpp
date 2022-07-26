/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    /*
        LCA(p,q)
        basic scenario is 
        left     ----      right
        
        p          |         q      ->this will directly work on if(right and left) this case
        p          |         NULL   ->directly return left
        NULL       |          q     ->directly return right
        NULL       |         NULL   ->simply return NULL
        
    */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //Here root is my current node.
        if(root->val==p->val or root->val==q->val)
        //Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
        {return root;}
        
        //condition of leaf node and there is no exist 
        if(!root->left and !root->right)
        {return NULL;}
        
        //Initially
        TreeNode*left=NULL;
        TreeNode*right=NULL;
        
        //same as recursive call for our left side
        if(root->left)
        {left=lowestCommonAncestor(root->left,p,q);}
        
        //Now recursive call for our right side
        if(root->right)
        {right=lowestCommonAncestor(root->right,p,q);}
        
        //if p and q both are present then return directly root val
        if(right and left)
        {return root;}
        
        return right==NULL?left:right; //If right NULL left return
    }
};