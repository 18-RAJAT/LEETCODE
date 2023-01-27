class Solution {
public:
    bool dfs(string word,unordered_set<string>&s)
    {
        int n=word.size();
        if(s.count(word))
        {
            return true;
        }
        for(int i=0;i<n;++i)
        {
            if(s.count(word.substr(0,i)) and dfs(word.substr(i),s))
            {
                return true;
            }
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string>s(words.begin(),words.end());
        vector<string>res;
        for(auto word:words)
        {
            s.erase(word);
            if(dfs(word,s))
            {
                res.push_back(word);
            }
            s.insert(word);
        }
        return res;      
    }
};