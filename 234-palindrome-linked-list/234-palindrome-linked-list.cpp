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
    bool isPalindrome(ListNode* head) {
        if(head==nullptr or head->next==nullptr){return true;}
//         ListNode*front=head,*mid=head,*fast=head;
//         while(fast)
//         {
//             fast=fast->next;
//             if(fast){fast=fast->next,mid=mid->next;}
//         }
        
//         ListNode*previous=nullptr;
//         while(mid)
//         {
//             ListNode*temp=mid->next;
//             mid->next=previous;
//             previous=mid;
//             mid=temp;
//         }
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast->next!=nullptr and fast->next->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
            slow->next=revList(slow->next);
        slow=slow->next;
        
        while(slow!=nullptr)
        {
            if(head->val!=slow->val){return false;}
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
        ListNode*revList(ListNode*head)
    {
            ListNode*prev=nullptr;
            ListNode*nxtval=nullptr;
            
            while(head!=nullptr)
            {
                nxtval=head->next;
                head->next=prev;
                prev=head;
                head=nxtval;
            }
            
            return prev;
    }
};