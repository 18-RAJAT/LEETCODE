class Solution {
public:
    int minimumLengthEncoding(vector<string>& w) {
      set<string>a(w.begin(),w.end()),b(w.begin(),w.end());
        for (auto x:a)
            for (int i=1; i<x.size(); ++i)
                b.erase(x.substr(i));
        int minlen=0;
        for (auto x: b)
            minlen+=(int)x.size()+1;
        return minlen;   
    }
};