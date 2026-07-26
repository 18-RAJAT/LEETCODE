class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=1,check=1;
        sort(nums.begin(),nums.end());
        ans=nums[0]*nums[1]*nums[n-1];
        check=nums[n-3]*nums[n-2]*nums[n-1];
        return (ans<check)?check:ans;
    }
};