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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        //Temp will be pointing to head 
        ListNode* temp = head;
        
        
        for(int i=0;i<k;++i)
        {
            //Base case
            if(temp == NULL)
            {
                return head;
            }
            
            //now head will be pointing to the next
            temp = temp->next;
        }
        
        ListNode* current = head;
        ListNode* previous = NULL;
        ListNode* next = NULL;
        
        for(int i=0;i<k;++i)
        {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        
        head->next = reverseKGroup(current,k);
        
        return previous;
        
    }
};