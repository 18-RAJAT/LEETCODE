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
    bool isCompleteTree(TreeNode* root) {
		
        queue<TreeNode*>q;
		q.push(root);
		bool flag=false;
		while(not q.empty())
        {
			TreeNode*tmp=q.front();
			q.pop();
			if(tmp==nullptr)
            {
				flag=true;
			}
			else
            {
				if(flag==true)
                {
					return false;
				}
				q.push(tmp->left);
                q.push(tmp->right);
			}
		}
		return true;
	}
};
