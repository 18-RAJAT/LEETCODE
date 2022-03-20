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
    
    vector<TreeNode*> buildtree(int start,int end)
    {
        vector<TreeNode*> answer;
        
        if(start > end)
        {
            answer.push_back(NULL);
            return answer;
        }
        
        for(int i= start;i<=end;++i)
        {
            vector<TreeNode*> leftsubtree = buildtree(start,i-1); //construct left subtree
            vector<TreeNode*> rightsubtree = buildtree(i+1,end); //construct right subtree
            
            for(int j=0;j<leftsubtree.size();++j)
            {
                for(int k=0;k<rightsubtree.size();++k)
                {
                    //Create root with i value...!!
                    TreeNode* root = new TreeNode(i);
                    
                    root->left = leftsubtree[j];
                    root->right = rightsubtree[k];
                    
                    answer.push_back(root);
                }
            }
        }
        
        return answer;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        
        return buildtree(1,n);
        
    }
};