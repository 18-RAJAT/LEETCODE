class Solution{
    struct TrieNode
    {
        int count=0;
        TrieNode* children[26]={};
    };
    TrieNode* root=new TrieNode();
    void insert(string& word)
    {
        TrieNode* node=root;
        for(char c:word)
        {
            int index=c-'a';
            if(!node->children[index]) node->children[index]=new TrieNode();
            node=node->children[index];
            node->count++;
        }
    }
    int getPrefixScore(const string& word){
        TrieNode* node=root;
        int score=0;
        for(char c:word)
        {
            node=node->children[c-'a'];
            score+=node->count;
        }
        return score;
    }
public:
    vector<int> sumPrefixScores(vector<string>& words){
        for(auto& it:words) insert(it);
        vector<int> ans;
        for(string& it:words) ans.push_back(getPrefixScore(it));
        return ans;
    }
};