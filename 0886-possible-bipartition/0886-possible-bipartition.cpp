class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>color(n+1,0);
        vector<int>adj[n+1];
        
        int m=dislikes.size();
        for(int i=0;i<m;++i)
        {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        for(int i=1;i<=n;++i)
        {
            if(color[i]==0)
            {
                queue<int>que;
                que.push(i);
                color[i]=1;
                
                while(!que.empty())
                {
                    int x=que.size();
                    int node=que.front();que.pop();
                    
                    for(int i=0;i<x;++i)
                    {
                        for(auto &it:adj[node])
                        {
                            if(color[node]==color[it])
                            {
                                return false;
                            }
                            if(color[it]==0)
                            {
                                color[it]-=color[node];
                                que.push(it);
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};