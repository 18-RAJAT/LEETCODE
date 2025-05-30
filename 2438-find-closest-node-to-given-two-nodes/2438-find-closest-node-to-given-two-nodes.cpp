class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int>adj[n];
        for(int i=0;i<n;++i)
        {
            if(~edges[i])
            {
                adj[i].push_back(edges[i]);
            }
        }
        queue<vector<int>>q;
        q.push({node1,0});
        q.push({node2,1});
        vector<vector<bool>>vis(n,vector<bool>(2,false));
        int ans=INT_MAX;
        bool flag=false;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                int num=q.front()[0];
                int idx=q.front()[1];
                q.pop();
                vis[num][idx]=true;
                if(vis[num][1-idx])
                {
                    ans=min(ans,num);
                    flag=true;
                }
                for(auto& it:adj[num])
                {
                    if(!vis[it][idx])
                    {
                        q.push({it,idx});
                    }
                }
            }
            if(flag)
            {
                break;
            }
        }
        if(ans==INT_MAX)
        {
            return -1;
        }
        else
        {
            return ans;
        }      
    }
};