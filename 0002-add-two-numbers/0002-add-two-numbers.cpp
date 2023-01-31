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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*head=new ListNode(0);
        ListNode*temp=head;
        int carry=0;
        int sum;
        while(l1 or l2 or carry)
        {
            sum=0;
            if(l1)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            /*
                cases
                1.If carry is 1 then it will add 1 to sum and carry will be 0 again
                2.If sum is 10 then carry will be 1 and sum will be 0
                3.if sum is 10 then tmp will be 0 and carry will be 1
            */
            sum+=carry;
            carry=sum/10;
            ListNode*tmp=new ListNode(sum%10);
            temp->next=tmp;
            temp=temp->next;
        }
        return head->next;
    }
};
//Time Complexity is O(max(l1,l2))