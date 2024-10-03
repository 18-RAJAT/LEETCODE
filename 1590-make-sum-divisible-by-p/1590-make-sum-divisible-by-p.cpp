class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int total=0,n=nums.size(),target;
        for(int i=0;i<n;++i)
        {
            total=(total+nums[i])%p;
        }
        if(total==0)return 0;
        target=total;
        unordered_map<int,int>mp;
        mp[0]=-1;
        int prefix=0,res=n;
        for(int i=0;i<n;++i)
        {
            prefix=(prefix+nums[i])%p;
            int needed=(prefix-target+p)%p;
            if(mp.find(needed)!=mp.end())res=min(res,i-mp[needed]);
            mp[prefix]=i;
        }
        return res==n?-1:res;
    }
};