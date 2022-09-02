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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*>que;
        que.push(root);
        vector<double>result;
        while(!que.empty())
        {
            int m=que.size();
            double sum=0;
            for(int i=0;i<m;++i)
            {
                TreeNode*current=que.front();que.pop();
                sum+=current->val;
                
                if(current->left){que.push(current->left);}
                if(current->right){que.push(current->right);}
            }
            double average=sum/m;result.push_back(average);
        }return result;
    }
};