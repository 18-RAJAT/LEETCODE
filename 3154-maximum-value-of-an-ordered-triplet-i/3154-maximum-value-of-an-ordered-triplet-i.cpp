class Solution{
public:
    long long maximumTripletValue(vector<int>&nums){
        int n=nums.size();
        vector<long long>pref(n,-1),suf(n,-1);
        for(int i=1;i<n;++i)pref[i]=max(pref[i-1],(long long)nums[i-1]);
        for(int i=n-2;~i;--i)suf[i]=max(suf[i+1],(long long)nums[i+1]);
        long long res=0;
        for(int i=1;i<n-1;++i)res=max(res,(pref[i]-nums[i])*suf[i]);
        return res;
    }
};