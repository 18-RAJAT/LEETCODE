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
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string>result;
        
        string answer;
        printNodes(root,answer,result);
        
        return result;
    }
    
    void printNodes(TreeNode* root,string answer,vector<string>& result)
    {
        if(root == NULL)
        {
            return;
        }
        
        answer += to_string(root->val) + "->";
        
        if(root->left == NULL and root->right == NULL)
        {
            answer.erase(answer.length()-2,2);
            result.push_back(answer);
        }
        
        printNodes(root->left,answer,result);
        printNodes(root->right,answer,result);
    }
};