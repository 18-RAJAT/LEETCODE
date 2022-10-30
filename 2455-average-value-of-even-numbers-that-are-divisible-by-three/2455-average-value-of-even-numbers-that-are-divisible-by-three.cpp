class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum=0;int ct=0;
        for(auto it:nums)
        {
            if(it%2==0 and it%3==0)
            {
                sum+=it;
                ct++;
            }
        }
        if(ct!=0)
        {
            return sum/ct;
        }
        return 0;
    }
};