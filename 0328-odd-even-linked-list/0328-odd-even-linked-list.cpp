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
    ListNode* oddEvenList(ListNode* head) {
        
        //Taking the virtually head of odd
        ListNode* oddHead=new ListNode(0);
        ListNode* odd = oddHead;
        
        //Taking the virtually head of even
        ListNode* evenHead=new ListNode(0);
        ListNode* even=evenHead;
        
        ListNode* current=head;
        
        int counter=1;
        
        while(current)
        {
            if(counter%2==1)
            {
//odd next value is current then we will pointing next one like odd -> next same as even case
                odd->next=current;
                odd=odd->next;
            }
            else
            {
                //Checking even case 
                even->next=new ListNode(current->val);
                even = even->next;
            }
            counter++;
            current=current->next;
        }
         //Attatch all of them 
        odd->next=evenHead->next;
        
        return oddHead->next;
    }
};