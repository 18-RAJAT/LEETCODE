class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int n=grid.size(),m=grid[0].size();
        int k=0,startX=0,startY=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(grid[i][j]=='@')//starting point
                {
                    startX=i;
                    startY=j;
                }
                if(grid[i][j]>='A' && grid[i][j]<='F')
                {
                    k++;
                }
            }
        }
        queue<pair<int,pair<int,int>>>que;
        que.push({startX,{startY,0}});
        int visited[n+1][m+1][70];
        memset(visited,0,sizeof(visited));
        visited[startX][startY][0]=1;
        
        int level=0;
        while(!que.empty())
        {
            int sza=que.size();
            for(int j=0;j<sza;++j)
            {
                int x=que.front().first;
                int y=que.front().second.first;
                int bitMask=que.front().second.second;
                que.pop();
                
                if(bitMask==((1<<k)-1))
                {
                    return level;
                }
                vector<pair<int,int>>direction={{-1,0},{1,0},{0,-1},{0,1}};
                for(auto& it:direction)
                {
                    int nx=x+it.first;
                    int ny=y+it.second;
                    
                    int mask=bitMask;
                    
                    if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]!='#')//wall
                    {
                        if(isupper(grid[nx][ny]))
                        {
                            if(!(bitMask&(1<<(grid[nx][ny]-'A'))))//upper
                            {
                                continue;
                            }
                        }
                        if(islower(grid[nx][ny]))
                        {
                            mask=(bitMask|(1<<(grid[nx][ny]-'a')));//lower
                        }
                        if(!visited[nx][ny][mask])
                        {
                            que.push({nx,{ny,mask}});
                            visited[nx][ny][mask]=1;
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};