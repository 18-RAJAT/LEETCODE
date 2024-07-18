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
    int countPairs(TreeNode* root,int distance)
    {
        this->distance=distance;
        recur(root,0);
        return ans;
    }
private:
    int ans=0,distance;
    vector<int>recur(TreeNode* root,int depth)
    {
        vector<int>ans;
        if(!root)return ans;
        if(!root->left && !root->right)
        {
            ans.push_back(depth);
            return ans;
        }
        vector<int> left=recur(root->left,depth+1),right=recur(root->right,depth+1);
        int L=left.size(),R=right.size();
        for(int l=0,r=R-1;l<L && r>=0;++l)
        {
            while(r>=0 && left[l]-depth+right[r]-depth>distance)r--;this->ans+=r+1;
        }
        ans.resize(L+R);
        merge(left.begin(),left.end(),right.begin(),right.end(),ans.begin());
        return ans;
    }
};