class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;
        return path(head,root) || isSubPath(head,root->left) || isSubPath(head,root->right);
    }

    bool path(ListNode* head, TreeNode* root) 
    {
        if (!head) return true;
        if (!root) return false;
        if (head->val==root->val)
        {
            return path(head->next,root->left) || path(head->next,root->right);
        }
        return false;
    }
};