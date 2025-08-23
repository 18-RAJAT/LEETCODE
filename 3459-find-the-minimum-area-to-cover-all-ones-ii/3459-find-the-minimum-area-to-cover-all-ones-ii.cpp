class Solution{
public:
    int Area(vector<vector<int>>& grid,int R1,int R2,int C1,int C2)
    {
        int MnR=R2,MxR=R1,MnC=C2,MxC=C1;
        for(int i=R1;i<=R2;++i)
        {
            for(int j=C1;j<=C2;++j)
            {
                if(grid[i][j])
                {
                    MnR=min(MnR,i),MxR=max(MxR,i),MnC=min(MnC,j),MxC=max(MxC,j);
                }
            }
        }
        return MnR>MxR || MnC>MxC?INT_MAX/3:(MxR-MnR+1)*(MxC-MnC+1);
    }
    vector<vector<int>>Grid(vector<vector<int>>& grid)
    {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>ar(n,vector<int>(m));
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                ar[i][j]=grid[j][i];
            }
        }
        return ar;
    }
    int recur(vector<vector<int>>& grid)
    {
        int ans=INT_MAX,m=grid.size(),n=grid[0].size();
        for(int i=0;i<m-2;++i)
        {
            for(int j=i+1;j<m-1;++j)
            {
                ans=min(ans,Area(grid,0,i,0,n-1)+Area(grid,i+1,j,0,n-1)+Area(grid,j+1,m-1,0,n-1));
            }
        }
        for(int i=0;i<m-1;++i)
        {
            for(int j=0;j<n-1;++j)
            {
                ans=min(ans,Area(grid,0,i,0,n-1)+Area(grid,i+1,m-1,0,j)+Area(grid,i+1,m-1,j+1,n-1));
                ans=min(ans,Area(grid,0,i,0,j)+Area(grid,0,i,j+1,n-1)+Area(grid,i+1,m-1,0,n-1));
            }
        }
        return ans;
    }
    int minimumSum(vector<vector<int>>&grid) {
        vector<vector<int>>ar=Grid(grid);
        return min(recur(grid),recur(ar));
    }
};