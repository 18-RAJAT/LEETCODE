class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int l=0,r=1e9;
        //Invariant
        while(r-l>1)
        {
            long long int m=l+(r-l)/2;
            long long int sum=0;
            for(int i=0;i<n;++i)sum+=(nums[i]+m-1)/m;
            (sum<=threshold)?r=m:l=m;
        }
        return r;
    }
};