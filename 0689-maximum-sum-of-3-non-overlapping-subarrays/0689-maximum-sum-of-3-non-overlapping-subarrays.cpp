class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>&nums,int k) {
        int n=nums.size(),sza=n-k+1;
        vector<int>arr(sza,0),pref(sza,0),suf(sza,0);
        int sum=0;
        for(int i=0;i<n;++i)
        {
            sum+=nums[i];
            if(i>=k-1) arr[i-k+1]=sum,sum-=nums[i-k+1];
        }
        int res=0;
        for(int i=0;i<sza;++i)
        {
            if(arr[i]>arr[res]) res=i;
            pref[i]=res;
        }
        res=sza-1;
        for(int i=sza-1;~i;--i)
        {
            if(arr[i]>=arr[res]) res=i;
            suf[i]=res;
        }
        vector<int>ans(3,0);
        int mxi=0;
        for(int i=k;i<sza-k;++i)
        {
            int l=pref[i-k],r=suf[i+k];
            int calc=arr[l]+arr[i]+arr[r];
            if(mxi<calc) mxi=calc,ans={l,i,r};
        }
        return ans;
    }
};