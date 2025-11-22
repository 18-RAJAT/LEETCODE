class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size(),ans=0;
        for(auto& it:nums)
        {
            int rem=it%3;
            if(rem==1)ans++;
            else if(rem==2)ans++;
        }
        return ans;
    }
};