class WordDictionary {
public:    
    
    WordDictionary() {}
    
    bool find(string& word,int pos,WordDictionary* root){
        if(pos==word.size())
            return root->end;
        if(word[pos]!='.')
        {
            if(root->v[word[pos]-'a'])
                return find(word,pos+1,root->v[word[pos]-'a']);
            else
                return false;
        }
        else
        {
             for(auto it:root->v)
             {
                bool t=false;
                if(it)
                   t=find(word,pos+1,it);
                if(t)
                    return t;
            }
            return false;
        }
        return true;
    }
    
    void addWord(string word) {
        WordDictionary* root=this ;
        for(char ch:word)
        {
            if(root->v[ch-'a'])
                root=root->v[ch-'a'];
            else
            {
                root->v[ch-'a']=new WordDictionary();
                root=root->v[ch-'a'];
            }
        }
        root->end=true;
    }
    
    bool search(string word) {
        WordDictionary* root=this;
        return find(word,0,root);
    }
    
    private:
       vector<WordDictionary*>v{26};
       bool end=false;
    
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */