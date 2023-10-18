class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>>graph(n+1);
        vector<int>indegree(n+1);
        for(auto& it:relations)
        {
            graph[it[0]].push_back(it[1]);
            ++indegree[it[1]];
        }
        queue<int>q;
        for(int i=1;i<=n;++i)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>dp(n+1);
        while(q.size())
        {
            int node=q.front();
            q.pop();
            for(auto& it:graph[node])
            {
                dp[it]=max(dp[it],dp[node]+time[node-1]);
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;++i)
        {
            ans=max(ans,dp[i]+time[i-1]);
        }
        return ans;
    }
};