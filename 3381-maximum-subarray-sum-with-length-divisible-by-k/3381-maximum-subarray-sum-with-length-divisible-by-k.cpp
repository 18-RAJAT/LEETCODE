class Solution {
public:
    long long maxSubarraySum(vector<int>&nums,int k){
        long long ans=0;
        const long long INF=1e18;
        vector<long long>pref(k,INF);
        pref[0]=0;
        long long maxi=-1e18;
        for(int i=0;i<nums.size();++i)
        {
            ans+=nums[i];
            int rem=(i+1)%k;
            if(pref[rem]!=INF)
            {
                long long curr=ans-pref[rem];
                if(curr>maxi)maxi=curr;
            }
            if(ans<pref[rem])pref[rem]=ans;
        }
        return maxi;
    }
};