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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        function<int(int,int)>gcd=[&](int a,int b)
        {
            if(b==0)return a;
            return gcd(b,a%b);
        };
        if(!head||!head->next)
        {
            return head;
        }
        ListNode*current=head;
        while(current&&current->next)
        {
            int gcdVal=gcd(current->val,current->next->val);
            ListNode*newNode=new ListNode(gcdVal);
            newNode->next=current->next;
            current->next=newNode;
            current=current->next->next;
        }
        return head;
    }
};