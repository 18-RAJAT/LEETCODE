class Solution {
public:
    const int Mod=1e9+7;
    vector<vector<long long>>mul(vector<vector<long long>>& n1,vector<vector<long long>>& n2)
    {
        vector<vector<long long>>res(26,vector<long long>(26,0));
        for(int i=0;i<26;++i)
        {
            for(int k=0;k<26;++k)
            {
                if(n1[i][k]==0)continue;
                for(int j=0;j<26;++j)
                {
                    long long matrix_mul=n1[i][k]*n2[k][j];
                    res[i][j]=(res[i][j]+matrix_mul)%Mod;
                }
            }
        }
        return res;
    }
    vector<vector<long long>>power(vector<vector<long long>>& n1,long long exp)
    {
        vector<vector<long long>>res(26,vector<long long>(26,0));
        for(int i=0;i<26;++i)
        {
            res[i][i]=1;
        }
        while(exp>=1)
        {
            if(exp&1)res=mul(res,n1);
            n1=mul(n1,n1);
            exp>>=1;
        }
        return res;
    }
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<long long>dp(26,0);
        for(int i=0;i<s.size();++i)
        {
            dp[s[i]-'a']=(dp[s[i]-'a']+1)%Mod;
        }
        vector<long long>ndp=dp;
        vector<vector<long long>>matrix(26,vector<long long>(26,0));
        for(int i=0;i<26;++i)
        {
            int tmp=nums[i];
            for(int j=1;j<=tmp;++j)
            {
                int nxt=(i+j)%26;
                matrix[nxt][i]=(matrix[nxt][i]+1)%Mod;
            }
        }
        vector<vector<long long>>transform=power(matrix,t);
        vector<long long>ans(26,0);
        for(int i=0;i<26;++i)
        {
            for(int j=0;j<26;++j)
            {
                ans[i]=(ans[i]+transform[i][j]*dp[j])%Mod;
            }
        }
        long long res=0;
        for(int i=0;i<26;++i)
        {
            res=(res+ans[i])%Mod;
        }
        return res;
    }
};