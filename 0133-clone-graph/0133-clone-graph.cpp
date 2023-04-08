/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<Node*,Node*>copy;
        
        function<Node*(Node*)>dfs=[&](Node* node)->Node*
        {
            if(not node)
            {
                return nullptr;
            }
            if(copy.count(node))
            {
                return copy[node];
            }
            Node* clone=new Node(node->val);
            copy[node]=clone;
            for(auto x:node->neighbors)
            {
                clone->neighbors.push_back(dfs(x));
            }
            return clone;
        };
        return dfs(node);
    }
};