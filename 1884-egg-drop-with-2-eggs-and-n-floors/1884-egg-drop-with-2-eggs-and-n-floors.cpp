#define f1(i,s,e) for(int i=s;i<e;i++)
#define ff1(i,s,e) for(int i=s;i>=e;--i)
#define For1(i,n) (int i=0;i<n+1;++i)
#define cf(i,s,e) for(int i=s;i<=e;i++)

class Solution {
public:
    int twoEggDrop(int n) {
    //     int dp[n+1];
    //     dp[0]=0;
    //     dp[1]=1;
    //     dp[2]=2;
    //     for(int i=3;i<=n;i++)
    //     {
    //         dp[i]=INT_MAX;
    //         for(int j=1;j<i;j++)
    //         {
    //             int temp=1+max(dp[j-1],dp[i-j]);
    //             dp[i]=min(dp[i],temp);
    //         }
    //     }
    //     return dp[n];     
        // int dp[n];
        vector<int>dp{0};
        // memset(dp,0,sizeof(dp));
        cf(i,1,n)
        {
            int mn=INT_MAX;
            cf(j,1,i)
            {
                mn=min(mn,1+max(j-1,dp[i-j]));
            }
            dp.push_back(mn);
        }
        return dp.back();
    }
};