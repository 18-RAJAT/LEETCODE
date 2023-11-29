class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<int,int>>rotten;
        int fresh=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(grid[i][j]==2)
                {
                    rotten.emplace(make_pair(i,j));
                }
                else if(grid[i][j]==1)
                {
                    fresh++;
                }
            }
        }
        int ans=0;
        while(!rotten.empty())
        {
            int sz=rotten.size();
            while(sz--)
            {
                pair<int,int>current=rotten.front();
                rotten.pop();
                for(int i=0;i<4;++i)
                {
                    int row=current.first+dx[i];
                    int col=current.second+dy[i];
                    
                    if(row>=0 && row<n && col>=0 && col<m && grid[row][col]==1)
                    {
                        grid[row][col]=2;
                        rotten.emplace(make_pair(row,col));
                        fresh--;
                    }
                }
            }
            ans++;
        }
        if(fresh>=1)
        {
            return -1;
        }
        return max<int>(0,ans-1);
    }
};