class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n=cells.size();
        int move=0,ans=-1;
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        
        auto check=[&](int day)->int
        {
            vector<vector<int>>adj(row,vector<int>(col,0));
            vector<vector<bool>>visited(row,vector<bool>(col,false));
            
            auto conditionsCheck=[&](int i,int j)->bool
            {
                if(i>=0 && i<row && j>=0 && j<col && !visited[i][j] && adj[i][j]==0)
                {
                    return true;
                }
                return false;
            };
            function<void(int,int)>dfs=[&](int i,int j)->void
            {
                visited[i][j]=true;
                for(int k=0;k<4;++k)
                {
                    int xx=dx[k]+i;
                    int yy=dy[k]+j;
                    
                    if(conditionsCheck(xx,yy))
                    {
                        dfs(xx,yy);
                    }
                }
            };
            for(int i=0;i<day;++i)
            {
                int R=cells[i][0];
                int C=cells[i][1];
                R--;C--;
                adj[R][C]=true;
            }
            for(int i=0;i<col;++i)
            {
                if(!visited[0][i] && adj[0][i]==0)
                {
                    dfs(0,i);
                }
            }
            for(int i=0;i<col;++i)
            {
                if(visited[row-1][i])
                {
                    return true;
                }
            }
            return false;
        };
        while(move<=n)
        {
            int mid=move+(n-move)/2;
            if(check(mid))
            {
                ans=mid;
                move=mid+1;
            }
            else
            {
                n=mid-1;
            }
        }
        assert(ans!=-1);
        return ans;
    }
};