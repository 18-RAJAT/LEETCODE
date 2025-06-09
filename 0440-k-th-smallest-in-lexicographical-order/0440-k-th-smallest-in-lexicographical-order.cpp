class Solution {
public:
    int findKthNumber(int n, int k) {
        long long ans=1;
        k--;
        while(k)
        {
            long long check=0,first=ans,second=ans+1;
            while(first<=n)
            {
                check+=(second>n+1)?(n+1-first):(second-first);
                first*=10,second*=10;
            }
            if(check<=k)
            {
                ans++,k-=check;
            }
            else
            {
                if(ans<=n/10)ans*=10,k-=1;
            }
        }
        return ans;
    }
};