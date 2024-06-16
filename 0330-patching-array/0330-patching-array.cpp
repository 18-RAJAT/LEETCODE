class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long int sz=nums.size(),sum=0,count=0,i=0;
        for(;sum<n;)
        {
            sum=(i<sz && nums[i]<=1+sum)?sum+nums[i++]:(count++,sum*2+1);
        }
        return  count;
    }
};