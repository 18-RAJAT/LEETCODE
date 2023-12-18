class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int start=nums[0]*nums[1];
        int end=nums[n-1]*nums[n-2];
        return abs<int>(start-end);
    }
};