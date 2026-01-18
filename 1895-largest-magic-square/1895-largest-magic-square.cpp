class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>row(n,vector<int>(m+1,0));
        vector<vector<int>>col(n+1,vector<int>(m,0));
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                row[i][j+1]=row[i][j]+grid[i][j];
                col[i+1][j]=col[i][j]+grid[i][j];
            }
        }
        for(int k=min(n,m);k>=2;--k)
        {
            for(int r=0;r+k<=n;++r)
            {
                for(int c=0;c+k<=m;++c)
                {
                    int tar=row[r][c+k]-row[r][c],ok=1;
                    for(int i=r;i<r+k;++i)
                    {
                        if(row[i][c+k]-row[i][c]!=tar)
                        {
                            ok=0;
                            break;
                        }
                    }
                    for(int j=c;j<c+k && ok;++j)
                    {
                        if(col[r+k][j]-col[r][j]!=tar)
                        {
                            ok=0;
                            break;
                        }
                    }
                    int x=0,y=0;
                    for(int i=0;i<k && ok;++i)
                    {
                        x+=grid[r+i][c+i],y+=grid[r+i][c+k-1-i];
                    }
                    if(ok && x==tar && y==tar)return k;
                }
            }
        }
        return 1;
    }
};