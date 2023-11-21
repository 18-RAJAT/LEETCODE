class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        long long n=nums.size();
        vector<long long> rev(n);
        for(int i=0;i<n;++i)
        {
            long long x=nums[i];
            long long y=0;
            while(x)
            {
                y=y*10+x%10;
                x/=10;
            }
            rev[i]=y;
        }
        map<long long,long long> mp;
        for(int i=0;i<n;++i)
        {
            mp[nums[i]-rev[i]]++;
        }
        long long ans=0;
        for(auto& i:mp)
        {
            ans+=i.second*(i.second-1)/2;
        }
        return ans%1000000007;
    }
};