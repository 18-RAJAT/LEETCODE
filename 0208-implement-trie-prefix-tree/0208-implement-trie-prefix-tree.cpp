class Node {
public:
    bool word;
    map<char,Node*>children;
    Node():word(false) {};
};

class Trie {
public:
    Node*root;
    Trie() 
    {
        root=new Node();
    }
    
    void insert(string word) {
        auto* cur=root;
        for(auto c:word) 
        {
            auto& childMap=cur->children;
            if (childMap.find(c)==childMap.end()) 
            {
                childMap[c]=new Node();
            }
            cur=childMap[c];
        }
        cur->word=true;
    }
    
    bool search(string word) {
        auto* cur=root;
        for(auto c:word) 
        {
            auto& childMap=cur->children;
            if(childMap.find(c)!=childMap.end()) 
            {
                cur=childMap[c];
            } 
            else 
            {
                return false;
            }
        }
        return cur->word;
    }
    
    bool startsWith(string prefix) {
        auto* cur=root;
        for(auto c:prefix) 
        {
            auto& childMap=cur->children;
            if (childMap.find(c)!=childMap.end()) 
            {
                cur=childMap[c];
            } 
            else 
            {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */