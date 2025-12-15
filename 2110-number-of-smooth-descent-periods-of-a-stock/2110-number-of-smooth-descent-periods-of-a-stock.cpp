class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n=prices.size(),res=1;
        long long ans=0;
        for(int i=0;i<n;++i)
        {
            if(i==0)
            {
                ans+=res;
                continue;
            }
            if(prices[i]==prices[i-1]-1)res++;
            else res=1;
            ans+=res;
        }
        return ans;
    }
};