class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum=accumulate(nums.begin(),nums.end(),0LL);
        return sum%k;
    }
};