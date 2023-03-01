class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        auto cmp=[&](const pair<int,int>&a,const pair<int,int>&b)
        {
            return a.first<b.first;
        };
        set<int>st;
        int n=nums.size();
        for(int i=0;i<n;++i)
        {
            auto it=st.lower_bound(nums[i]-valueDiff);
            // if(it==st.end())
            // {
            //     return false;
            // }
            if(*it<=nums[i]+valueDiff and it!=st.end())
            {
                return true;
            }
            st.insert(nums[i]);
            if(i>=indexDiff)
            {
                st.erase(nums[i-indexDiff]);
            }
        }
        return false;
    }
};