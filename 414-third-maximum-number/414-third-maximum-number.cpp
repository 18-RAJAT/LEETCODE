class Solution {
public:
    int thirdMax(vector<int>& nums) {

        map<int,bool>m;
        for(auto i : nums)
        {
            m[i] = true;
        }
        nums = {};
        
        for(auto i : m)
        
            nums.push_back(i.first);
          int n = nums.size();
        return (n < 3) ? nums[n-1] : nums[n-3];
    }
};
