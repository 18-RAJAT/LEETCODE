class WordFilter {
public:
    unordered_map<string,int>um;
    WordFilter(vector<string>& words) {
        for(int k=0;k<words.size();k++)
        {
            string word=words[k];
            int n=word.size();
            for(int i=0;i<n;i++)
            {
                for(int j=n-1;j>=0;j--)
                {
                    um[word.substr(0,i+1)+'|'+word.substr(j)]=k;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        if(um.find(prefix+'|'+suffix)==um.end())
        {
            return -1;
        }
        return um[prefix+'|'+suffix];
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */


