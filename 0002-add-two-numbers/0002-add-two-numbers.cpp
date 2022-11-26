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
    ListNode*addingTwoLL(ListNode*l1,ListNode*l2,int generateCarry)
    {
        int digit1,digit2;
        int totalSum;
        
        if(l1==nullptr and l2==nullptr)
        {
            auto tp=new ListNode(1);
            // return nullptr;
            return generateCarry?tp:nullptr;
        }
        // else if(generateCarry)
        // {
        //     return new ListNode(1);
        // }
        // else
        // {
        //     return nullptr;
        // }
        if(l1)
        {
            digit1=l1->val;
        }
        else
        {
            digit1=0;
        }
        
        if(l2)
        {
            digit2=l2->val;
        }
        else
        {
            digit2=0;
        }
        
        // cout<<digit1<<" "<<digit2<<"\n";
        
        totalSum=digit1+digit2+generateCarry;
        
        // cout<<"Sum: "<<totalSum<<"\n"; |7,10,8|   l <- r move
        
        int generate=totalSum%10;
        int bitGen=totalSum/10;
        
        // cout<<generate<<" "<<bitGen<<"\n";
        
        return new ListNode(generate,addingTwoLL(l1?l1->next:l1,l2?l2->next:l2,bitGen));
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1)
        {
            // cout<<"value of "<<l1<<" "<<l2<<"\n";
            return l2;
        }
        if(!l2)
        {
            return l1;
        }
        return addingTwoLL(l1,l2,0);
    }
};