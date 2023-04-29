class Solution {
    public:
        int numSubarraysWithSum(vector<int>& nums, int goal) {
            array<int,100005>count{};
            count[0]=1;//to handle the case when sum-goal=0
            int allPossibleCount=0;//to store the count of all possible subarrays
            int sum=0;
            for(auto num:nums)
            {
                sum+=num;//calculating the sum of subarray
                if(goal<=sum)//if sum is greater than or equal to goal then we will check if there is any subarray with sum equal to sum-goal
                {
                    allPossibleCount+=count[sum-goal];//if there is any subarray with sum equal to sum-goal then we will add it to our answer
                }
                count[sum]++;//increasing the count of sum
            }
            return allPossibleCount;
        }
    };