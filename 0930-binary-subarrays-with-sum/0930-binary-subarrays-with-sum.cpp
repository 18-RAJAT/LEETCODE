class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        array<int,100005>count{};
        count[0]=1;
        int allPossibleCount=0;
        int sum=0;
        for(auto num:nums)
        {
            sum+=num;
            if(goal<=sum)
            {
                allPossibleCount+=count[sum-goal];
            }
            count[sum]++;
        }
        return allPossibleCount;
    }
};