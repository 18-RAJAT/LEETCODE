class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>&grid,vector<int>&queries) {
        vector<int>ans(queries.size(),0);
        int n=grid.size(),m=grid[0].size();
        vector<pair<int,int>>pq;
        for(int i=0;i<queries.size();++i)pq.push_back({queries[i],i});
        sort(pq.begin(),pq.end());
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        vector<vector<int>>track(n,vector<int>(m,0));
        track[0][0]=1;
        q.push({grid[0][0],{0,0}});
        int t=0;
        for(int j=0;j<pq.size();++j)
        {
            int a=pq[j].first,b=pq[j].second;
            while(!q.empty() && q.top().first<a)
            {
                int f1=q.top().second.first,f2=q.top().second.second;
                t++;
                q.pop();
                int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
                for(int i=0;i<4;++i)
                {
                    int x=dx[i]+f1,y=dy[i]+f2;
                    if(x>=0 && y>=0 && x<n && y<m && !track[x][y])
                    {
                        track[x][y]=1;
                        q.push({grid[x][y],{x,y}});
                    }
                }
            }
            ans[b]=t;
        }
        return ans;
    }
};