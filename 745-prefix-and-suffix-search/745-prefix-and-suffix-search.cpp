class WordFilter {
public:
        map<string,int>mp;
    WordFilter(vector<string>& words) {
            for(int i=0;i<words.size();++i)
            {
                    string w=words[i];
                    int n=w.size();
                    for(int j=0;j<n;++j)
                    {
                            for(int k=n-1;k>=0;--k)
                            {
                                    mp[w.substr(0,j+1)+'|'+w.substr(k)]=i;
                            }
                    }
            }
        
    }
    
    int f(string prefix, string suffix) {
        if(mp.find(prefix+'|'+suffix)==mp.end()){return -1;}
            return mp[prefix+'|'+suffix];
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */


