class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<int>a(n);
        for(int i=0;i<n;++i)a[i]=(nums[i]==0)?-1:1;
        map<int,int>mp;
        int sum=0,ans=0;
        for(int i=0;i<n;++i)
        {
            sum+=a[i];
            if(sum==0)ans=max(ans,i+1);
            else if(mp.count(sum))ans=max(ans,i-mp[sum]);
            else mp[sum]=i;
        }
        return ans;
    }
};