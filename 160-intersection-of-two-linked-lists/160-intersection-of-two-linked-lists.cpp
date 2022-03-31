/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        //At first i will created a new node of a  and b to the point of ListNode and = headA and headB....!!
     ListNode* a = headA;
     ListNode* b = headB;
        
        //Base condition(edge cases)
        if(a == NULL and b == NULL)
        {
            return NULL;
        }
        
        //This base is when a is not equal to b it mean no intersection is determined...!!
          while(a != b)
        {
            //Check the cases...!!
            a = !a ?  headB : a->next;
            b = !b ?  headA : b->next;
        }
        //And the return the value of 'a' this mean this will give us intrsection point of two LL
        return a;
    }
};