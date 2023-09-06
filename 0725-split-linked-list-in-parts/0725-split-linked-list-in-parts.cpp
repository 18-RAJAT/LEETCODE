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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode*temp=head;
        vector<ListNode*>ans(k);
        int cnt=0;//count of nodes
        while(temp)
        {
            cnt++;
            temp=temp->next;
        }
        int group=cnt/k;//no of nodes in each group
        int rem=cnt%k;//no of groups with extra node
        temp=head;//reset temp
        for(int i=0;i<k;i++)
        {
            int j=0;
            ListNode*NodeGrp=temp;//head of group
            ListNode*prev=nullptr;
            while(temp && j<group)//traverse till group size
            {
                prev=temp;
                temp=temp->next;
                j++;
            }
            if(rem>0)//if extra node is there
            {
                //add extra node to group
                prev=temp;
                temp=temp->next;
                rem--;
            }
            if(prev)prev->next=nullptr;//break link
            ans[i]=NodeGrp;//add group head to ans
        }
        return ans;
    }
};