class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        unordered_map<int,int>mp;
        mp[items[0][0]]=items[0][1];
        for(int i=1;i<items.size();++i)
        {
            mp[items[i][0]]=max(mp[items[i-1][0]],items[i][1]);
        }
        vector<int>arr;
        for(auto& it:mp)arr.push_back(it.first);
        sort(arr.begin(),arr.end());
        int n=queries.size();
        vector<int>ans(n);
        for(int i=0;i<n;++i)
        {
           auto it=upper_bound(arr.begin(),arr.end(),queries[i]);
            (it==arr.begin())?ans[i]=0:ans[i]=mp[*(--it)];
        }
        return ans;
    }
};