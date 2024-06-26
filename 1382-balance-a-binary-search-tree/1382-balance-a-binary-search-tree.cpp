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
	vector<int>arr;
	void dfs(TreeNode* root)
    {
			if(not root) return;
			dfs(root->left);
			arr.push_back(root->val);
			dfs(root->right);
	}

	TreeNode* recur(int left,int right)
    {
		if(left>right) return nullptr;
		int mid=(left+right)/2;
		int val=arr[mid]; 
		TreeNode* temp=new TreeNode(val);
		temp->left=recur(left,mid-1);
		temp->right=recur(mid+1,right);
		return temp;
	}

	TreeNode* balanceBST(TreeNode* root) {
		dfs(root);
		return recur(0,arr.size()-1);
	}
};