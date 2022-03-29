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
    ListNode* deleteDuplicates(ListNode* head) {
        
        //Creating a dummy node
        ListNode*dummy = new ListNode(0,head);
        
        ListNode* previous = dummy;
        
        //Base case
        while(head != NULL)
        {
            if(head->next != NULL and head->val == head->next->val)
            {
                //Again intering the base case 
                while(head->next != NULL and head->val == head->next->val)
                
                    head = head->next;
                
                //Here we will point at first previous ka next then head ka next   
                previous->next = head->next; 
            }   
            
            else
                
                //initilize the previous = previous point to the next node 
                previous = previous->next;
                
                //And then we will be doing this ki head will be point the next node 
                head = head->next;
            
        }
        
        //At the end we will be return the dummy will we pointing to the next then this thing we will be return
        return dummy->next;
        
    }
};
