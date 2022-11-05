class Trie{
    public:
    Trie* child[26];
    bool isEnd;
    int index;
    
    Trie()
    {
        for(int i=0;i<26;++i)
            child[i]=NULL;
        index=-1;
        isEnd=false;
    }
};
class Solution {
    void insert(Trie* root,string& word,int ind)
    {
        Trie* curr=root;
        
        for(auto ch:word)
        {
            if(!curr->child[ch-'a'])
                curr->child[ch-'a']=new Trie();
            curr=curr->child[ch-'a'];
        }
        curr->index=ind;
        curr->isEnd=true;
    }
    void search(int i,int j,int n,int m, vector<vector<char>>& board,unordered_set<int>& ans,Trie* root){
        if(i<0 or j<0 or i>=n or j>=m or board[i][j]=='*' or !root->child[board[i][j]-'a']) return;
        
        root=root->child[board[i][j]-'a'];
        
        if(root->isEnd) 
            ans.insert(root->index);
        
        char temp=board[i][j];
        
        board[i][j]='*';
        
        search(i+1,j,n,m,board,ans,root);
        search(i,j+1,n,m,board,ans,root);
        search(i,j-1,n,m,board,ans,root);
        search(i-1,j,n,m,board,ans,root);
        
        board[i][j]=temp;
        
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie *trie=new Trie();
        int n=board.size(), m=board[0].size();
        
        for(int i=0;i<words.size();++i)
            insert(trie,words[i],i);
        
        unordered_set<int>ans;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                search(i,j,n,m,board,ans,trie);
            }
        }
        
        vector<string>res;
        for(auto it=ans.begin();it!=ans.end();++it)
        {
            res.emplace_back(words[*it]);
        }
        return res;
        
    }
};