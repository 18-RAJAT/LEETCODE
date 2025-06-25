class Solution {
public:
    string minWindow(string s, string t) {
        //varibale size(Shrink-expand based on count match)... | hash map + sliding window shrink
        int n=s.size(),m=t.size();
        map<int,int>mp;
        for(int i=0;i<m;++i)mp[t[i]]++;
        int l=0,r=0,mn=INT_MAX,cnt=0,idx=-1;
        while(r<n)
        {
            if(mp[s[r]]>=1)cnt++;
            mp[s[r]]--;
            while(cnt==t.size())
            {
                if(r-l+1<mn)
                {
                    idx=l,mn=r-l+1;
                }
                mp[s[l]]++;
                if(mp[s[l]]>=1)cnt--;
                l++;
            }
            r++;
        }
        return idx==-1?"":string(s.begin()+idx,s.begin()+idx+mn);
    }
};