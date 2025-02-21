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
class FindElements {
    unordered_set<int>st;
    void recur(TreeNode* node, int val)
    {
        if(!node)return;
        node->val=val;
        st.insert(val);
        recur(node->left,2*val+1);
        recur(node->right,2*val+2);
    }
public:
    FindElements(TreeNode* root)
    {
        recur(root,0);
    }
    bool find(int target)
    {
        return st.count(target);
    }
};


/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */