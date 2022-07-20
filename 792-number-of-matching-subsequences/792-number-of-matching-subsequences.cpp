class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        map<string,int>mp;
        for(auto it:words){mp[it]++;}
        int ans=0;
        for(auto it:mp)
        {
            string x=it.first;
            int a=0,b=0;
            while(a<x.length() and b<s.length()){if(x[a]==s[b]){a++;}b++;}
            if(a==x.length()){ans+=it.second;}
        }
        return ans;
    }
};