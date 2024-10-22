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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long>PQ;
        queue<TreeNode*>Q;
        Q.push(root);
        while(!Q.empty())
        {
            int size= Q.size();
            long long sum=0;
            for(int i=0;i<size;++i)
            {
                TreeNode*curr=Q.front();
                    Q.pop();
                    sum+=curr->val;
                    if(curr->left) Q.push(curr->left);
                    if(curr->right) Q.push(curr->right);
            }
            PQ.push(sum);
        }
        if(PQ.size()<k) return -1;
        while(--k>0) PQ.pop();
        return PQ.top();
    }
};