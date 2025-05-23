class Solution {
private:
    void build_graph(vector<vector<int>>& edges,vector<vector<int>>& adj)
    {
        for(auto& it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
    }
    vector<int> find_increasing_indices(vector<int>& nums,int k)
    {
        vector<int>include;
        for(int i=0;i<nums.size();++i)
        {
            long long val=static_cast<long long>(nums[i])^k;
            if(val>nums[i])
            {
                include.push_back(i);
            }
        }
        return include;
    }
    long long calculate_even_sum(vector<int>& nums,vector<int>& include,int k)
    {
        long long ans=accumulate(nums.begin(),nums.end(),0LL);
        for(auto& it:include)
        {
            ans-=nums[it];
            long long add=static_cast<long long>(nums[it])^k;
            ans+=add;
        }
        return ans;
    }
    long long calculate_odd_sum(vector<int>& nums,vector<int>& include,int k,int n)
    {
        long long ans=accumulate(nums.begin(),nums.end(),0LL);
        long long ert=ans;
        for(auto& it:include)
        {
            ans-=nums[it];
            long long add=static_cast<long long>(nums[it])^k;
            ans+=add;
        }
        for(int i=0;i<include.size();++i)
        {
            long long add=static_cast<long long>(nums[include[i]])^k;
            long long curr_ans=ans-add+nums[include[i]];
            ert=max(ert,curr_ans);
        }
        vector<int>vis(n,0);
        for(auto& it:include)
        {
            vis[it]=1;
        }
        for(int i=0;i<n;++i)
        {
            for(auto& it:include)
            {
                if(vis[i]==0)
                {
                    long long add=static_cast<long long>(nums[i])^k;
                    long long curr_ans=ans-nums[i]+add;
                    ert=max(ert,curr_ans);
                }
            }
        }
        for(int i=0;i<n;++i)
        {
            if(vis[i]==0)
            {
                long long add=static_cast<long long>(nums[i])^k;
                long long curr_ans=ans-nums[i]+add;
                ert=max(ert,curr_ans);
            }
        }
        return ert;
    }
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n=nums.size();
        vector<vector<int>> adj(n);
        build_graph(edges,adj);
        vector<int> include=find_increasing_indices(nums,k);
        int sz=include.size();
        // for(int i=0;i<sz;++i)
        // {
        //     cout<<include[i]<<" ";
        // }
        // for(int i=0;i<sz;++i)
        // {
        //     for(int j=0;j<adj[include[i]].size();++j)
        //     {
        //         cout<<adj[include[i]][j]<<" ";
        //     }
        // }
        long long ans;
        (sz%2==0)?ans=calculate_even_sum(nums,include,k):ans=calculate_odd_sum(nums,include,k,n);
        return ans;
    }
};