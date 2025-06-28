class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0,sum=0;
        map<int,int>mp;
        mp[0]=1;
        for(int i=0;i<n;++i)
        {
            sum+=nums[i];
            int rem=sum%k;
            if(rem<0)rem+=k;
            if(mp.count(rem))ans+=mp[rem];
            mp[rem]++;
        }
        return ans;
    }
};