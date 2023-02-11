class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        nth_element(nums.begin(),nums.end()-k,nums.end());
        int tmp=n-k;
        return nums[tmp];
    }
};