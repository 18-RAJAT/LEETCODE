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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
       if(head == NULL)
       {
           return NULL;
       }
        
        ListNode* result = new ListNode(0,head);
        ListNode* previous = result;
        
        for(int i=0;i<left-1;++i)
            previous = previous->next;
        
        ListNode* current = previous->next;
        
        while(left++ < right)
        {
            ListNode* temp = current->next;
            current->next = temp->next;
            temp->next = previous->next;
            previous->next = temp;
        }
        
        return result->next;
        
    }
};