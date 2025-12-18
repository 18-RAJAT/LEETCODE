class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n=prices.size();
        long long sum=0,z=0,o=0;
        for(int i=0;i<n;++i)sum+=prices[i]*strategy[i];
        long long ans=sum;
        for(int i=0;i<n;++i)
        {
            z+=prices[i]*-strategy[i];
            o+=prices[i];
            int j=i-k;
            if(j>=0)z+=prices[j]*strategy[j];
            j=i-(k/2);
            if(j>=0)o-=prices[j];
            if(k-1<=i)ans=max(ans,sum+z+o);
        }
        return ans;
    }
};