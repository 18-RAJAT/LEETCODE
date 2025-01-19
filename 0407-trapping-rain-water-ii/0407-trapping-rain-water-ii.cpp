class Solution{
public:
    int trapRainWater(vector<vector<int>>& h){
        int n=h.size(),m=h[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(i==0 || j==0 || i==n-1 || j==m-1)
                {
                    pq.push({h[i][j],{i,j}});
                    vis[i][j]=1;
                }
            }
        }
        int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
        int ans=0;
        while(!pq.empty())
        {
            auto tp=pq.top();
            pq.pop();
            for(int i=0;i<4;++i)
            {
                int r=tp.second.first+dir[i][0],c=tp.second.second+dir[i][1];
                if(r>=0 && r<n && c>=0 && c<m && vis[r][c]==0)
                {
                    int tmp=max(0,tp.first-h[r][c]);
                    ans+=tmp;
                    vis[r][c]=1;
                    int nh=max(tp.first,h[r][c]);
                    pq.push({nh,{r,c}});
                }
            }
        }
        return ans;
    }
};