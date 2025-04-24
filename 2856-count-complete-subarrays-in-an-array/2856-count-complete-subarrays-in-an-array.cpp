class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>st;
        for(auto&it:nums)
        {
            st.insert(it);
        }
        map<int,int>mp;
        int sz=st.size();
        int ans=0;
        int i=0;
        for(int j=0;j<n;++j)
        {
            mp[nums[j]]++;
            while(sz==mp.size())
            {
                ans+=n-j;
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                {
                    mp.erase(nums[i]);
                }
                i++;
            }
        }
        return ans;
    }
};