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
        
        stack<ListNode*>stack1;
        stack<ListNode*>stack2;
        
        //L2 list k lie
        while(l1)
        {
            stack1.push(l1);
            l1 = l1->next;
        }
        
        //L2 list k lie
        
        while(l2)
        {
            stack2.push(l2);
            l2 = l2->next;
        }
        
        //Firstly head will be initilize NULL 
        
        ListNode* head = NULL;
        
        //Taking a carry
        int carry = 0;
        
        //Then entering the while loop
        while(carry or !stack1.empty() or !stack2.empty())
        {
            //when stack empty
            if(!stack1.empty())
            {
                //then stack k top k sath add then pop
                carry += stack1.top()->val,stack1.pop();
            }
            
            //same as stack 2 k sath 
            if(!stack2.empty())   
            {
                //carry add then pop
                carry += stack2.top()->val,stack2.pop();
            }
            
            //generate carry....!!
            ListNode* node = new ListNode(carry % 10);
            
            node->next = head;
            
            head = node;
            
            carry = carry / 10;
            
        }
        return head;
    }
};