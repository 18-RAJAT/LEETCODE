#define imax INT_MAX
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
            // Using bellman Ford
        vector<int>dis(n+1,imax);
            dis[k]=0;
            for(int i=1;i<n;++i)
            {
                    for(int j=0;j<times.size();++j)
                    {
                            int u=times[j][0];
                            int v=times[j][1];
                            int w=times[j][2];
                            if(dis[u]!=imax and dis[u]+w<dis[v])
                            {
                                    dis[v]=w+dis[u];
                            }
                    }
            }
            int answer=0;
            for(int i=1;i<=n;++i)
            {
                         if(dis[i]==imax){return -1;}
                         answer=max(answer,dis[i]);
            }
            return answer;
    }
};