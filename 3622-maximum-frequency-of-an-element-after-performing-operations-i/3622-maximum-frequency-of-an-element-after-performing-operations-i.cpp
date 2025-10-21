class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        map<int,int>mp;
        for(int i=0;i<n;++i)mp[nums[i]]++;
        int ans=1;
        for(int i=1;i<=nums[n-1];++i)
        {
            int r=lower_bound(nums.begin(),nums.end(),i+k+1)-nums.begin();
            int l=lower_bound(nums.begin(),nums.end(),i-k)-nums.begin();
            int check=mp.count(i)?mp[i]:0,res=min(numOperations+check,r-l);
            ans=max(ans,res);
        }
        return ans;
    }
};