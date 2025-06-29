class Solution {
public:
    int numSubseq(vector<int>& nums,int target) {
        long long int n=nums.size();
        sort(nums.begin(),nums.end());
        long long int l=0,r=n-1;
        long long int ans=0;
        auto power=[&](long long int a,long long int b)->long long int
        {
            long long ans=1;
            while(b>0)
            {
                if(b%2==1)
                {
                    ans=(ans*a)%1000000007;
                }
                a=(a*a)%1000000007;
                b/=2;
            }
            return ans;
        };
        while(l<=r)
        {
            long long int sum=nums[l]+nums[r];
            if(sum<=target)
            {
                ans+=power(2,r-l);
                ans%=1000000007;
                l++;
            }
            else r--;
        }
        return ans;
    }
};