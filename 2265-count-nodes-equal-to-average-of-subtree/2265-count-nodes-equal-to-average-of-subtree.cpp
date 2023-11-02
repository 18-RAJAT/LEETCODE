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
    int averageOfSubtree(TreeNode* root) {
        function<void(TreeNode*,int&,int&)>sum=[&](TreeNode* root,int& Tsum,int& count)->void
        {
            if(!root)
            {
                return;
            }
            Tsum+=root->val;
            count++;
            sum(root->left,Tsum,count);
            sum(root->right,Tsum,count);
        };
        if(!root)
        {
            return 0;
        }
        int Tsum=0,count=0;
        int countNodes=0;
        sum(root,Tsum,count);
        int avg=Tsum/count;
        if(avg==root->val)
        {
            countNodes++;
        }
        return countNodes+averageOfSubtree(root->left)+averageOfSubtree(root->right);
    }
};