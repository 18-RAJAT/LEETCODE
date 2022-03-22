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


/*

APPROACH ->

At first we take two dummy pointers for our separate parts of a linked list and then
connect all nodes less then x together and all greater then x together at last
finally connect the two parts using the dummy pointers assigned as their head nodes...!!

*/
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* node1 = new ListNode();
        ListNode* node2 = new ListNode();
        
        ListNode*ptr1,*ptr2;
        
        ptr1 = node1;
        ptr2 = node2;
        
        while(head)
        {
            if(head->val < x)
            {
                ptr1->next = head;
                ptr1 = ptr1->next;
            }
            
            else
            {
                ptr2->next = head;
                ptr2 = ptr2->next;
            }
            
            head = head->next;
        }
        
        ptr2->next = NULL;
        ptr1->next = node2->next;
        
        return node1->next;
        
    }
};




