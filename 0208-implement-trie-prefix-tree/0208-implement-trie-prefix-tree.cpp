struct TrieNode
{
    TrieNode* child[26]={};
    bool isEnd=false;
};
class Trie
{
    TrieNode* root;
    public:
    Trie(){root=new TrieNode();}
    
    void insert(string word) {
        TrieNode* cur=root;
        for(char& it:word)
        {
            int i=it-'a';
            if(!cur->child[i])cur->child[i]=new TrieNode();
            cur=cur->child[i];
        }
        cur->isEnd=true;
    }

    bool search(string word) {
        TrieNode* cur=root;
        for(char& it:word)
        {
            int i=it-'a';
            if(!cur->child[i])return false;
            cur=cur->child[i];
        }
        return cur->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* cur=root;
        for(char& it:prefix)
        {
            int i=it-'a';
            if(!cur->child[i])return false;
            cur=cur->child[i];
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