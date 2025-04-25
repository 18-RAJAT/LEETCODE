class Solution{
public:
    long long countInterestingSubarrays(vector<int>&nums,int modulo,int k){
        int n=nums.size();
        vector<long long>v(n,0);
        if(nums[0]%modulo==k)v[0]=1;
        map<long long,long long>mp;
        for(int i=1;i<n;++i)
        {
            if(nums[i]%modulo==k)v[i]=v[i-1]+1;
            else v[i]=v[i-1];
        }
        long long ans=0;
        for(int i=0;i<n;++i)
        {
            if(v[i]%modulo==k)ans++;
            if(mp.find((v[i]-k+modulo)%modulo)!=mp.end())ans+=mp[(v[i]-k+modulo)%modulo];
            mp[v[i]%modulo]++;
        }
        return ans;
    }
};