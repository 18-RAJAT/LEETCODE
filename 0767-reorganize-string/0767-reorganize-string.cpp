class Solution {
public:
    static bool comp(pair<char, int> &A, pair<char, int> &B) {
        return A.second > B.second;
    }
    string reorganizeString(string s) {
        int fz[26]={0};
        for(int i=0;i<s.length();++i)
        {
            fz[s[i]-'a']++;
        }
        vector<pair<char,int>>vp;
        for(int i=0;i<26;++i)
        {
            vp.push_back({i+'a',fz[i]});
        }
        sort(vp.begin(),vp.end(),comp);
        if(vp[0].second>(s.length()+1)/2)return "";
        int k=0;
        for(int i=0;i<s.length();i+=2)
        {
            s[i]=vp[k].first;
            vp[k].second--;
            if(vp[k].second==0)k++;
        }
        for(int i=1;i<s.length();i+=2)
        {
            s[i]=vp[k].first;
            vp[k].second--;
            if(vp[k].second==0)k++;
        }
        return s;
    }
};