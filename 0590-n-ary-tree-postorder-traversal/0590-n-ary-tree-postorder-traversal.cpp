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
    vector<int> postorder(Node* root) {
        vector<int>answer;
        if(root)recur(answer,root);
        return answer;
    }
    void recur(vector<int> &answer,Node* node)
    {
        if(!(node->children.empty()))
        for(auto& it:node->children)recur(answer,it);
        answer.push_back(node->val);
    }
};