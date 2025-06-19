class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int ans=0;
        set<int>st;
        for(auto& it:nums)
        {
            st.insert(it);
        }
        int res=-1;
        for(auto& it:st)
        {
            if(res<it)
            {
                res=it+k,ans++;
            }
        }
        return ans;
    }
};