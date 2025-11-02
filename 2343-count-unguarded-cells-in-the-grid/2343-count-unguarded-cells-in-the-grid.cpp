class Solution {
public:
    int countUnguarded(int m,int n,vector<vector<int>>& guards,vector<vector<int>>& walls) {
        vector<vector<char>>grid(m,vector<char>(n,'F'));
        for(auto& it:guards)
        {
            grid[it[0]][it[1]]='G';
        }
        for(auto& it:walls)
        {
            grid[it[0]][it[1]]='W';
        }
        for(int i=0;i<guards.size();++i)
        {
            int x=guards[i][0],y=guards[i][1];
            for(int j=x-1;~j;--j)
            {
                if(grid[j][y]=='W' || grid[j][y]=='G')break;
                grid[j][y]='X';
            }
            for(int j=x+1;j<m;++j)
            {
                if(grid[j][y]=='W' || grid[j][y]=='G')break;
                grid[j][y]='X';
            }
            for(int j=y-1;~j;--j)
            {
                if(grid[x][j]=='W' || grid[x][j]=='G')break;
                grid[x][j]='X';
            }
            for(int j=y+1;j<n;++j)
            {
                if(grid[x][j]=='W' || grid[x][j]=='G')break;
                grid[x][j]='X';
            }
        }
        int ans=0;
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(grid[i][j]=='F')ans++;
            }
        }
        return ans;
    }
};