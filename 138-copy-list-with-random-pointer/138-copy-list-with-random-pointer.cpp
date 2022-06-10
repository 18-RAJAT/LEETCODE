/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*,Node*>mp;
           Node*tp=head;
            while(tp!=NULL)
            {
                    Node* copy=new Node(tp->val);
                    mp[tp]=copy;
                    tp=tp->next;
            }
            tp=head;
            while(tp!=NULL)
            {
                    mp[tp]->next=mp[tp->next];
                    mp[tp]->random=mp[tp->random];
                    tp=tp->next;
            }
            return mp[head];
    }
};