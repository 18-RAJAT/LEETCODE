class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n=s.size(),ans=0,cur=0,bit=log2(k)+1;
        for(int i=0;i<n;++i)
        {
            char c=s[n-1-i];
            if(c=='1')
            {
                if(i<bit && cur+(1<<i)<=k)cur+=1<<i,ans++;
            }
            else ans++;
        }
        return ans;
    }
};