class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if(grid[0][1]>1 && grid[1][0]>1)return -1;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<pair<int,int>>valid{{1,0},{0,1},{-1,0},{0,-1}};
        vector<vector<bool>>cells(grid.size(),vector<bool>(grid[0].size(),false));
        cells[0][0]=true;
        pq.push({0,0,0});
        while(!pq.empty())
        {
            vector<int>T=pq.top();
            pq.pop();
            if(T[1]==grid.size()-1 && T[2]==grid[0].size()-1)
            {
                return T[0];
            }
            for(int i=0;i<valid.size();++i)
            {
                int x=T[1]+valid[i].first,y=T[2]+valid[i].second;
                if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && !cells[x][y])
                {
                    cells[x][y]=true;
                    if(grid[x][y]>T[0])
                    {
                        if((grid[x][y]-T[0])%2==1)
                        {
                            pq.push({grid[x][y],x,y});
                        }
                        else
                        {
                            pq.push({grid[x][y]+1,x,y});
                        }
                    }
                    else
                    {
                        pq.push({T[0]+1,x,y});
                    }
                }
            }
        }
        return -1;
    }
};