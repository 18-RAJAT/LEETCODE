class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> mp;
        int n=colors.length();
        vector<int>inDegree(n,0);
        int ans=-1;
        for(auto& it:edges)
        {
            int src=it[0],dest=it[1];
            mp[src].push_back(dest);
            inDegree[dest]++;
        }
        queue<int>pending;
        vector<vector<int>>dp(n,vector<int>(26,0));
        for(int i=0;i<n;++i)
        {
            if(inDegree[i]==0)
            {
                dp[i][colors[i]-'a']++;
                pending.push(i);
            }
        }
        vector<int>topo;
        while(not pending.empty())
        {
            int src=pending.front();
            pending.pop();
            topo.push_back(src);
            for(auto dest:mp[src])
            {
                char destColor=colors[dest];
                for(int color=0;color<26;++color)
                    dp[dest][color]=max(dp[dest][color],dp[src][color]+(color==(destColor-'a')));
                inDegree[dest]--;
                if(inDegree[dest]==0)pending.push(dest);
            }
        }
        if(topo.size()==n)
        {
            for(auto& it:dp)
                for(auto& freq:it)ans=max(freq,ans);
            return ans;
        }
        else return -1;
    }
};