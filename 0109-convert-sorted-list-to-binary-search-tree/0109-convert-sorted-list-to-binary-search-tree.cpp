/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode*makeTree(int i,int j,vector<int>a)
    {
        if(i>j)
        {
            return nullptr;
        }
        int mid=(i+j)/2;
        TreeNode*root=new TreeNode(a[mid]);
        root->left=makeTree(i,mid-1,a);
        root->right=makeTree(mid+1,j,a);
        
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>a;
        if(head==nullptr)
        {
            return nullptr;
        }
        while(head)
        {
            a.push_back(head->val);
            head=head->next;
        }
        return makeTree(0,a.size()-1,a);
    }
};