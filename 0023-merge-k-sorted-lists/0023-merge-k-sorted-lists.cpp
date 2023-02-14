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
    ListNode* Merge(ListNode*l1,ListNode*l2)
    {
        //base
        if(l1==nullptr)
        {
            return l2;
        }
        if(l2==nullptr)
        {
            return l1;
        }
        
        //chk
        ListNode*current=nullptr;
        if(l1->val<=l2->val)
        {
            current=l1;
            current->next=Merge(l1->next,l2);
        }
        else
        {
            current=l2;
            current->next=Merge(l1,l2->next);
        }
        return current;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==1)
        {
            return lists[0];
        }
        ListNode*tmp=new ListNode(-2147483648);//INT_MIN
        for(int i=0;i<lists.size();++i)
        {
            if(lists[i]==nullptr)
            {
                continue;
            }
            //call
            Merge(tmp,lists[i]);
        }
        //move nxt
        return tmp->next;
    }
};