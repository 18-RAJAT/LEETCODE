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
        
        //Taking the virtually head 
        ListNode* oddHead = new ListNode(0);
        ListNode* odd = oddHead;
        
        //Taking the virtually head
        ListNode* evenHead = new ListNode(0);
        ListNode* even = evenHead;
        
        //ListNode initiallly initilize head
        ListNode* current = head;
        
        //taking one counter variable to visit all the nodes
        int counter=1;
        
        while(current)
        {
            //odd even check condition
            if(counter % 2 == 1)
            {
     //odd next value is current then we will pointing next one like odd ka next same as even case
                odd->next = current;
                odd = odd->next;
            }
            else
            {
                //Checking even case 
               even->next = new ListNode(current->val);
                even = even->next;
            }
            
            //Here we will terminate the loop and increment the counter variable
            counter++;
            
            //Then current value pointing the next one.
            current = current->next;
        }
        
         //Attatch all of them 
        odd->next = evenHead->next;
        
        return oddHead->next;
    }
};