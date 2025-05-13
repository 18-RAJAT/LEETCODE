class Solution {
public:
    const int Mod=1e9+7;
    int lengthAfterTransformations(string s, int t) {
        vector<long long>dp(26,0);
        for(int i=0;i<s.size();++i)
        {
            dp[s[i]-'a']=(dp[s[i]-'a']+1)%Mod;
        }
        vector<long long>ndp(26,0);
        for(int i=0;i<t;++i)
        {
            fill(ndp.begin(),ndp.end(),0);
            for(int j=0;j<26;++j)
            {
                if(j==25)
                {
                    ndp[0]=(ndp[0]+dp[j])%Mod;
                    ndp[1]=(ndp[1]+dp[j])%Mod;
                }
                else ndp[j+1]=(ndp[j+1]+dp[j])%Mod;
            }
            dp=ndp;
        }
        long long ans=0;
        for(int i=0;i<26;++i)
        {
            ans=(ans+dp[i])%Mod;
        }
        return ans;
    }
};