class WordDictionary {
public:
    WordDictionary() {}
    
    void addWord(string word) {
        WordDictionary* tmp = this;
        for(char c : word){
            if(!tmp->words[c - 'a']) tmp->words[c - 'a'] = new WordDictionary();
            tmp = tmp->words[c - 'a'];
        }
        tmp->isWord = true;
    }

    bool search(string word){
        return search(word,this,0);
    }
     
    bool search(string& word, WordDictionary* dict, int index) {
        if(index == word.size() && dict->isWord) return true;
        if(index == word.size()) return false;
        
        if(word[index] == '.'){
            for(int i = 0; i < 26; i++){
                if(dict->words[i] && search(word, dict->words[i], index + 1)) return true;;
            }
        }
        else{
            if(!dict->words[word[index] - 'a']) return false;
            return search(word, dict->words[word[index] - 'a'], index + 1);
        }          
        
        return false;
    }

    bool isWord = false;
    WordDictionary* words[26] = { [0 ... 25] = nullptr };
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */