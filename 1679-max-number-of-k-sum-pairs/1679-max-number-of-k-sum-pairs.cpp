//TLE 

// class Solution {
// public:
//     int maxOperations(vector<int>& nums, int k) {
//        sort(nums.begin(),nums.end());
//             int start = 0;
//             int end = nums.size()-1;
//             int result = 0;
            
//             while(start < end)
//             {
//                     if(nums[start] + nums[end] == k)
//                     {
//                             result++;
//                             start++;
//                             end--;
//                     }
//                     else if(nums[start] + nums[end] > k)
//                     {
//                             start++;
//                             end--;
//                     }
//             }
//             return result;
//     }
// };


class Solution {
public:
    int maxOperations(vector<int>& nums, int k)
    {
        unordered_map<int, int> freq;
        int ans = 0;
        for(auto cur: nums)
        {
            int complement = k - cur;
            if(freq[complement] > 0){ans++; freq[complement]--;
        }
            else freq[cur]++;
        }
        return ans;
    }
};