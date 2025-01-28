class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int>dir={0,-1,0,1,0};
        int ans=0,MaximumFish=0;
         for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                ans=0;
                if(grid[i][j]!=0)
                {
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    ans+=grid[i][j],grid[i][j]=0;
                    while(!q.empty())
                    {
                        for(int k=0;k<4;++k)
                        {
                            int Row=q.front().first+dir[k];
                            int Col=q.front().second+dir[k+1];
                            if(Row>=0 && Row<n && Col>=0 && Col<m && grid[Row][Col]!=0)
                            {
                                ans+=grid[Row][Col];
                                q.push({Row,Col});
                                grid[Row][Col]=0;
                            }
                        }
                        q.pop();
                    }
                }
                MaximumFish=max(MaximumFish,ans);
            }
         }
        return MaximumFish;
    }
};