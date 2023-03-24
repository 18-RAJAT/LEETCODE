class Solution {
public:
    int minReorder(int n, vector<vector<int>>& con) {
        vector<vector<int>> adj(n),adj1(n);
        vector<int>vis(n,0);
        vis[0]=1;
        for(auto a:con)
        {
            adj[a[0]].push_back(a[1]);
            adj1[a[1]].push_back(a[0]);
        }
        int ans=0;
        queue<int>q;
        q.push(0);
        while(not q.empty())
        {
            int a=q.front();
            vis[a]=1;
            q.pop();
            for(auto it:adj[a])
            {
                if(not vis[it])
                {
                    ans++;
                    q.push(it);
                }
            }
            for(int it:adj1[a])
            {
                if(not vis[it])
                {
                    q.push(it);
                }
            }
        }
        return ans;
    }
};