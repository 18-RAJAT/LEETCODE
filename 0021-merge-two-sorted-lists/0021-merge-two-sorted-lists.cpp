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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*head=nullptr;
        ListNode*tail=nullptr;
        
        if(list1==nullptr)
        {
            return list2;
        }
        if(list2==nullptr)
        {
            return list1;
        }
        if(list1->val<=list2->val)
        {
            //head and tail merged
            head=list1;
            tail=list1;
            list1=list1->next;
        }
        else
        {
            head=list2;
            tail=list2; 
            list2=list2->next;
        }
        while(list1!=nullptr && list2!=nullptr)
        {
            if(list1->val<=list2->val)
            {
                //update
                tail->next=list1;
                tail=list1;
                list1=list1->next;
            }
            else
            {
                tail->next=list2;
                tail=list2;
                list2=list2->next;
            }
        }
        if(list1!=nullptr)
        {
            tail->next=list1;//add the remaining list1 to the merged list
        }
        if(list2!=nullptr)
        {
            tail->next=list2;
        }
        return head;
    }
};