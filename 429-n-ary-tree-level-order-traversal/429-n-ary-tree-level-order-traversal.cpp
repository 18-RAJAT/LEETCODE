/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root){return{};}
        queue<Node*>que;
        vector<vector<int>>result;
        
        que.push(root);
        
        while(que.size())
        {
            int m=que.size();
            vector<int>v;
            while(m--)
            {
                auto current=que.front();que.pop();
                v.push_back(current->val);
                
                for(auto child:current->children)que.push(child);
            }
            result.push_back(v);
        }
        return result;
    }
};