class Solution {
public:
    #define ll long long
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        int val = INT_MAX;
        int idx = 0;
        
        ll sum = 0,cur = 0;
        for(int i:nums)sum += i;
 
        for(int i=0;i<n;i++)
        {
            cur += nums[i];
            sum -= nums[i];
            
            ll c_val = 0;
            if(i == n-1)
            {
                c_val = cur/(i+1);
            }
            else c_val = abs((cur)/(i+1)-((sum)/(n-i-1)));
            if(c_val < val)
            {
                val = c_val;
                idx = i;
                // idx++;
            }
        } 
        return idx;
    }
};
   