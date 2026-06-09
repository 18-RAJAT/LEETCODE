class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        return(*max_element(nums.begin(),nums.end())-(*min_element(nums.begin(),nums.end())))*1LL*k;
    }
};