class Solution{
public:
    vector<int> maxValue(vector<int>&nums){
        int n=nums.size();
        vector<int>pref(n),suf(n);
        pref[0]=nums[0],suf[n-1]=nums[n-1];
        for(int i=1;i<n;++i)pref[i]=max(nums[i],pref[i-1]);
        for(int i=n-2;~i;--i)suf[i]=min(nums[i],suf[i+1]);
        vector<int>ans(n);
        ans[n-1]=pref[n-1];
        for(int i=n-2;~i;--i)
        {
            if(pref[i]>suf[i+1])ans[i]=ans[i+1];
            else ans[i]=pref[i];
        }
        return ans;
    }
};