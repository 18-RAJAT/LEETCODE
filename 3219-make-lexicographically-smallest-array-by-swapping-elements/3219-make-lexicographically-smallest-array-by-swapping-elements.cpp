class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>>vp;
        int n=nums.size();
        for(int i=0;i<n;++i)
        {
            vp.push_back(make_pair(nums[i],i));
        }
        sort(vp.begin(),vp.end());
        iota(nums.begin(),nums.end(),0);
        sort(nums.begin(),nums.end(),[&](int i,int j){return vp[i].first<vp[j].first;});
        set<int>st;
        vector<int>ans;
        st.insert(vp[0].second);
        ans.push_back(vp[0].first);
        for(int i=1;i<n;++i)
        {
            if(abs(vp[i].first-vp[i-1].first)<=limit)
            {
                st.insert(vp[i].second);
                ans.push_back(vp[i].first);
            }
            else
            {
                int k=0;
                for(auto& it:st)nums[it]=ans[k++];
                st.clear();
                ans.clear();
                st.insert(vp[i].second);
                ans.push_back(vp[i].first);
            }
        }
        int res=0;
        for(auto& it:st)
        {
            nums[it]=ans[res];
            res++;
        }
        return nums;
    }
};