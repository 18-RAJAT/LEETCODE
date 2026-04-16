class Solution{
public:
    vector<int> solveQueries(vector<int>&nums,vector<int>&queries){
        int n=nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;++i)mp[nums[i]].push_back(i);
        vector<int>dist(n,-1);
        for(auto& it:mp)
        {
            vector<int>& id=it.second;
            int k=id.size();
            if(k<2)continue;
            for(int i=0;i<k;++i)
            {
                int prev=id[(i-1+k)%k],x=(id[i]-prev+n)%n;
                int nxt=id[(i+1)%k],y=(nxt-id[i]+n)%n;
                dist[id[i]]=min(x,y);
            }
        }
        vector<int>ans(queries.size());
        for(int i=0;i<queries.size();++i)ans[i]=dist[queries[i]];
        return ans;
    }
};