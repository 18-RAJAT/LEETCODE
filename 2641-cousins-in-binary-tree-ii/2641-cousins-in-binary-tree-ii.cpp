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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root==NULL)return root;
        queue<TreeNode*>q;
        q.push(root);
        int nextsum=root->val;
        while(!q.empty())
        {
            int cur=nextsum;
            nextsum=0;
            int size=q.size();
            while(size--)
            {
                TreeNode* node=q.front();
                q.pop();
                int sum=0;
                node->val=cur-node->val;
                if(node->left)
                {
                    sum+=node->left->val;
                    nextsum+=node->left->val;
                }
                if(node->right)
                {
                    sum+=node->right->val;
                    nextsum+=node->right->val;
                }
                if(node->left)
                {
                    node->left->val=sum;
                    q.push(node->left);
                }
                if(node->right)
                {
                    node->right->val=sum;
                    q.push(node->right);
                }
            }
        }
        return root;
    }
};