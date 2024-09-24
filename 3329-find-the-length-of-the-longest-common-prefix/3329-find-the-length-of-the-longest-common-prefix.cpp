struct TrieNode
{
    TrieNode* children[10]={nullptr};
};

class Trie
{
public:
    TrieNode* root;
    Trie()
    {
        root=new TrieNode();
    }
    void insert(string& num)
    {
        TrieNode* node=root;
        for(char& c:num)
        {
            int idx=c-'0';
            if(!node->children[idx]) node->children[idx]=new TrieNode();
            node=node->children[idx];
        }
    }
    int searchLongestPrefix(string& num)
    {
        TrieNode* node=root;
        int len=0;
        for(char& c:num)
        {
            int idx=c-'0';
            if(!node->children[idx]) break;
            node=node->children[idx];
            len++;
        }
        return len;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1,vector<int>& arr2) {
        Trie trie;
        for(auto& x:arr1)
        {
            string s1=to_string(x);
            trie.insert(s1);
        }
        int maxLen=0;
        for(auto& y:arr2)
        {
            string s2=to_string(y);
            maxLen=max(maxLen,trie.searchLongestPrefix(s2));
        }
        return maxLen;
    }
};