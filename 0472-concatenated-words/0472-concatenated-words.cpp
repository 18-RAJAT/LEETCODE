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
    void insert(string& s)
    {
        TrieNode* cur=root;
        for(char& it:s)
        {
            int i=it-'a';
            if(!cur->child[i])cur->child[i]=new TrieNode();
            cur=cur->child[i];
        }
        cur->isEnd=true;
    }
    //DFS to check if a word can be formed by concatenating at least 2 other words
    bool dfs(string& s,int idx,int cnt,unordered_map<int,bool>& dp)
    {
        if(idx==s.size())return cnt>=2;
        if(dp.count(idx))return dp[idx];
        TrieNode* cur=root;
        for(int i=idx;i<s.size();++i)
        {
            int c=s[i]-'a';
            if(!cur->child[c])break;
            cur=cur->child[c];
            if(cur->isEnd)
            {
                //if prefix is a word, try remaining part recursively
                if(dfs(s,i+1,cnt+1,dp))return dp[idx]=true;
            }
        }
        return dp[idx]=false;
    }
    bool isConcat(string& s)
    {
        unordered_map<int,bool>dp;
        return dfs(s,0,0,dp);
    }
};
class Solution {
public:
    vector<string>findAllConcatenatedWordsInADict(vector<string>& words) {
        Trie t;
        for(string& it:words)
        {
            if(it.size())t.insert(it);
        }
        vector<string>ans;
        for(string& it:words)
        {
            if(t.isConcat(it))ans.push_back(it);
        }
        return ans;
    }
};