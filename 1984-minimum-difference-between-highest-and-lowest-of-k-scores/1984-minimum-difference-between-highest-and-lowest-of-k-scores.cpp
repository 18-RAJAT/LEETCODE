class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<k)return 0;
        sort(nums.begin(),nums.end());
        int i=0,j=i+k-1,mx=INT_MAX;
        while(j<n)
        {
            mx=min(mx,nums[j]-nums[i]);
            i++,j++;
        }
        return mx;
    }
};