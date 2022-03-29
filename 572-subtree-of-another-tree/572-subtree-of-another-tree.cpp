class Solution {
    
    bool isSameTree(TreeNode* root1 , TreeNode* root2)
    {
        //Base Cases
        if(!root1 and !root2)
        {
            return  true;
        }
        
        if(!root1 or !root2)
        {
            return false;
        }
        
        if(root1->val != root2->val)
        {
            return false;
        }
        
        return isSameTree(root1->left,root2->left) and isSameTree(root1->right,root2->right);
        
    }
    
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        //Base Cases
        if(!root and !subRoot)
        {
            return true;
        }
        
        if(!root or !subRoot)
        {
            return false;
        }
        
        return isSameTree(root,subRoot) or isSubtree(root->left,subRoot) or isSubtree(root->right,subRoot);
        
    }
};