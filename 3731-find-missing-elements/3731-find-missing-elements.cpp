class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>missing;
        int cur=nums[0],n=nums.size();
        for(int i=0;i<n;++i)
        {
            while(cur<nums[i])missing.push_back(cur++);
            cur=nums[i]+1;
        }
        return missing;
    }
};