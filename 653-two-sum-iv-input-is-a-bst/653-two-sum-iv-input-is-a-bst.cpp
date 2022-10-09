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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return help(root, k, s);
    }
    bool help(TreeNode* n, int k, unordered_set<int>& s){
        if(!n) return false;
        if(s.find(n->val) != s.end()) return true;
        else{
            s.insert(k - n->val);
            return help(n->left, k, s) || help(n->right, k, s);
        }
    }
};