class Solution{
public:
    int rev(int n)
    {
        long long ans=0;
        while(n>=1)
        {
            int dig=n%10;
            ans=ans*10+dig;
            n=n/10;
        }
        return ans;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int ans=INT_MAX;
        for(int i=0;i<n;++i)
        {
            int x=rev(nums[i]);
            if(mp.find(nums[i])!=mp.end())ans=min(ans,abs(i-mp[nums[i]]));
            mp[x]=i;
        }
        return ans==INT_MAX?-1:ans;
    }
};