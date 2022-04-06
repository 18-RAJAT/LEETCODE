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
    
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        int jump1 = 1;
        ListNode *temp1 = list1;
        while (jump1 < a)
        {
            temp1 = temp1->next;
            jump1++;
        } 
        
        int jump2 = 1;
        
        ListNode *temp2 = list1;
        while(jump2 <= b)
        {
            temp2 = temp2->next;
            jump2++;
        }   
        
        ListNode* temp3 = list2;
        
        while(temp3->next != NULL)
        {
            temp3 = temp3->next;
        }
        
        temp1->next = list2;
        
        temp3->next = temp2->next;
        
        return list1;
        
    }
};