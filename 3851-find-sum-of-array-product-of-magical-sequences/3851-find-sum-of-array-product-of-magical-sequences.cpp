class Solution {
public:
    const int Mod=1e9+7;
    static int dp[31][31][50][32],C[31][31];
    void recur()
    {
        if(C[0][0])return;
        C[0][0]=1;
        for(int i=1;i<=30;++i)
        {
            C[i][0]=C[i][i]=1;
            for(int j=1;j<i;++j)
            {
                C[i][j]=(C[i-1][j-1]+C[i-1][j])%Mod;
            }
        }
    }
    int dfs(int m,int k,int i,int ok,vector<int>& a,int n)
    {
        int cnt=__builtin_popcount(ok);
        if(m<0 || k<0 || m+cnt<k)return 0;
        if(m==0)return k==cnt;
        if(i>=n)return 0;
        if(~dp[m][k][i][ok])return dp[m][k][i][ok];
        long long ans=0,res=1,x=a[i];
        for(int j=0;j<=m;++j)
        {
            long long tmp=C[m][j]*res%Mod;
            int t1=ok+j,t2=t1>>1,bt=t1&1;
            ans=(ans+tmp*dfs(m-j,k-bt,i+1,t2,a,n))%Mod;
            res=res*x%Mod;
        }
        return dp[m][k][i][ok]=ans;
    }
    int magicalSum(int m,int k,vector<int>& nums)
    {
        recur();
        memset(dp,-1,sizeof(dp));
        return dfs(m,k,0,0,nums,nums.size())%Mod;
    }
};
int Solution::C[31][31];
int Solution::dp[31][31][50][32];