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

//USING - RECURSION
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head,ListNode* tail = NULL) {
        
        //Base case
        if(head == tail)
        {
            return NULL;
        }
        
        //Using 2 pointers
        
        //Fast will be initilize to head
        ListNode* fast = head;
        
        //Slow will be initilize to head
        ListNode* slow = head;
        
        //Fast and Fast next iff tail k not equal hai tho loop run
        while(fast != tail and fast->next != tail)
        {
            //slow ka next
            slow = slow->next;
            //fast ka next ka next
            fast = fast->next->next;
        }
        
        TreeNode* root = new TreeNode(slow->val);
        
        root->left = sortedListToBST(head,slow);
        
        root->right = sortedListToBST(slow->next,tail);
        
        return root;
        
    }
};





