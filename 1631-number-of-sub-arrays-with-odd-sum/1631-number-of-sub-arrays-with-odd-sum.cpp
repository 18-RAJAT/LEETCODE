class Solution {
public:
    int numOfSubarrays(vector<int>&arr) {
        int n=arr.size();
        long long sum=0,odd=0,even=0,ans=0;
        for(int i=0;i<n;++i)
        {
            sum+=arr[i];
            (sum&1)?(odd++,ans+=even+1):(even++,ans+=odd);
        }
        return ans%1000000007;
    }
};