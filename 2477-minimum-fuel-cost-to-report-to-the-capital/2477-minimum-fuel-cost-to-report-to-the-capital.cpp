#define ll long long
#define sza(x) ((int)x.size())
#define f1(i,s,e) for(long long int i=s;i<e;i++)
#define MP make_pair
#define PB push_back
#define PF push_front

class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        ll ans=0;
        function<int(vector<vector<int>>& g,int k,int node,vector<int>&vis)>dfs=[&](vector<vector<int>>& g,int k,int node,vector<int>&vis)
        {
            vis[node]=1;
            ll num=1;
            f1(i,0,sza(g[node]))
            {  
                if(vis[g[node][i]]==0)
                {
                    vis[g[node][i]]=1;
                    num+=dfs(g,k,g[node][i],vis);

                }
            }
            ans+=num/k;
            if(num%k!=0)
            {
                ans++;
            }
            return num;
        };

        int sz=sza(roads);
        vector<vector<int>>adj(sz+1);
        f1(i,0,sz)
        {
            adj[roads[i][0]].PB(roads[i][1]);
            adj[roads[i][1]].PB(roads[i][0]);
        }

        vector<int>visited(sz+1,0);
        visited[0]=1;//1
        f1(i,0,sza(adj[0]))
        {
            dfs(adj,seats,adj[0][i],visited);
        }
        return ans;
    }
};