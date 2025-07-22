class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans=0;
        unordered_set<int>st;
        for(int i=0,j=0,res=0;j<nums.size();++j)
        {
            while(st.count(nums[j]))
            {
                st.erase(nums[i]);
                res-=nums[i],i++;
            }
            st.insert(nums[j]);
            res+=nums[j];
            ans=max(ans,res);
        }
        return ans;
    }
};