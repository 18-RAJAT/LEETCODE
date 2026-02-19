class Solution {
public:
    int countBinarySubstrings(string s) {
        int n=s.size(),prev=0,cur=1,ans=0;
        for(int i=1;i<n;++i)
        {
            if(s[i]==s[i-1])cur++;
            else
            {
                ans+=min(cur,prev);
                prev=cur,cur=1;
            }
        }
        ans+=min(prev,cur);
        return ans;
    }
};