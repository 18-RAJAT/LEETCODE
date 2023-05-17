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
class Solution {
public:
    int maximum=0;
    ListNode *left=nullptr;
    void maxSum(ListNode *right)
    {
        if(not right)
        {
            return;
        }
        maxSum(right->next);
        maximum=max(maximum,left->val+right->val);
        left=left->next;

    }
    int pairSum(ListNode* head) {
        left=head;
        maxSum(head);
        return maximum;

    }
};