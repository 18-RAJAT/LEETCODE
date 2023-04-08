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
        map<Node*,Node*>m;
        
        function<Node*(Node*)>dfs=[&](Node* node)->Node*
        {
            if(not node)
            {
                return 0;
            }
            if(m.count(node))
            {
                return m[node];
            }
            Node* clone=new Node(node->val);
            m[node]=clone;
            for(auto x:node->neighbors)
            {
                clone->neighbors.push_back(dfs(x));
            }
            return clone;
        };
        return dfs(node);
    }
};