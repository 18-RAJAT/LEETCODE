class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int>st,res;
        int n=nums.size();
        for(int i=0;i<n;++i)
        {
            for(int j=i;j<n;++j)
            {
                st.insert(nums[i]^nums[j]);
            }
        }
        for(auto& it:st)
        {
            for(auto& jt:nums)
            {
                res.insert(it^jt);
            }
        }
        return res.size();
    }
};