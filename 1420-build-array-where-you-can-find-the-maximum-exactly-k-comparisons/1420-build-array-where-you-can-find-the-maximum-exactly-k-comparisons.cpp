class Solution {
    public:
        int dp[105][105][105];
        int m;
        int recur(int fill,int check,int k)
        {
            //base case
            if(k<0)
            {
                return 0;
            }
            //pruning
            if(check==0)
            {
                return k==0;
            }
            //memoization
            int& ans=dp[fill][check][k];
            if(~ans)
            {
                return ans;
            }
            int res=0;
            for(int i=1;i<=m;++i)
            {
                //eliminating the case when we are not filling the array
                if(i>fill)
                {
                    //take
                    res+=recur(i,check-1,k-1);
                }
                else
                {
                    //not take
                    res+=recur(fill,check-1,k);
                }
                res%=1000000007;
            }
            return ans=res;

            assert(~dp[fill][check][k]>=0);
        }
        int numOfArrays(int n, int m, int k) {
            //choice 1: Take element greater than last used k is reduced by 1
            //choice 2: Take element less than or equal to last k not reduced
            this->m=m;//number of elements
            memset(dp,-1,sizeof(dp));
            return recur(0,n,k);
        }
    };