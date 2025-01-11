class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.size();
        if(n<k)return false;
        vector<int>freq(26,0);
        for(int i=0;i<n;++i)freq[s[i]-'a']++;
        for(auto& it:freq)
        {
            if(it&1)k--;
        }
        return k>=0?true:false;
    }
};