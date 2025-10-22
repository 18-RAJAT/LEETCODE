class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int,int>mp,fz;
        set<int>st;
        for(auto& it:nums)
        {
            fz[it]++,mp[it-k]++,mp[it+k+1]--;
            st.insert(it),st.insert(it-k),st.insert(it+k+1);
        }
        int res=0,ans=1;
        for(auto& it:st)
        {
            int tmp=it;
            res+=mp[tmp];
            int mn=min(res-fz[tmp],numOperations);
            ans=max(ans,fz[tmp]+mn);
        }
        return ans;
    }
};