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
        pfNodes(root,answer,result);
        
        return result;
    }
    
    void pfNodes(TreeNode* root,string answer,vector<string>& result)
    {
        if(root==nullptr)
        {
            return;
        }
        
        answer += to_string(root->val) + "->";
        
        if(root->left==nullptr and root->right==nullptr)
        {
            answer.erase(answer.length()-2,2);
            result.push_back(answer);
        }
        
        pfNodes(root->left,answer,result);
        pfNodes(root->right,answer,result);
    }
};