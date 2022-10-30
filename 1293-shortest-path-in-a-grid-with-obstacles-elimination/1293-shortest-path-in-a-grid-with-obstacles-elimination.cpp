class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
    
        vector<vector<int>>directions{{-1,0},{0,-1},{1,0},{0,1}};
        
        int m=grid.size(),n=grid[0].size();
        vector<vector<vector<bool>>>visited(m,vector<vector<bool>>(n,vector<bool>(k+1)));

        queue<vector<int>>q;
        q.push({0,0,k});
        
        visited[0][0][k]=true;
        
        int countSteps=0;
        
        while(!q.empty())
        {
            int sz=q.size();
            for(int i=0;i<sz;++i)
            {
                auto cur=q.front();
                q.pop();
                
                if(cur[0]==m-1 and cur[1]==n-1) 
                {
                    return countSteps;
                }

                for(auto dir:directions)
                {
                    int newRow=dir[0]+cur[0];
                    int newCol=dir[1]+cur[1];
                    int obstacle=cur[2];
                    
                    if(newRow>=0 and newCol>=0 and newRow<m and newCol<n)
                    {
                        
                        if(grid[newRow][newCol]==0 and !visited[newRow][newCol][obstacle])
                        {
                            q.push({newRow,newCol,obstacle});
                            visited[newRow][newCol][obstacle]=true;
                        }
                        if(grid[newRow][newCol]==1 and obstacle>0 and !visited[newRow][newCol][obstacle-1])
                        {
                            q.push({newRow,newCol,obstacle-1});
                            visited[newRow][newCol][obstacle-1]=true;
                        }
                    }
                }
            }
            countSteps++;
        }
        return -1;
    }
};