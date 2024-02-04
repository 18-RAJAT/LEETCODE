class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n<m)
        {
            return "";
        }
        vector<int>mp(256,0);
        for(int i=0;i<m;++i)
        {
            mp[t[i]]++;
        }
        int start=0;
        int end=0;
        int min_len=INT_MAX;
        int count=0;
        int start_index=-1;
        for(int i=0;i<n;++i)
        {
            mp[s[i]]--;
            if(mp[s[i]]>=0)
            {
                count++;
            }
            if(count==m)
            {
                while(mp[s[start]]<0)
                {
                    mp[s[start]]++;
                    start++;
                }
                int len=i-start+1;
                if(len<min_len)
                {
                    min_len=len;
                    start_index=start;
                }
            }
        }
        if(start_index==-1)
        {
            return "";
        }
        return s.substr(start_index,min_len);
    }
};