class Solution{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>&grid,int k){
        int n=grid.size(),m=grid[0].size();
        k%=n*m;
        while(k--)
        {
            vector<vector<int>>ar=grid;
            for(int i=0;i<n;++i)
            {
                for(int j=1;j<m;++j)ar[i][j]=grid[i][j-1];
            }
            for(int i=0;i<n-1;++i)ar[i+1][0]=grid[i][m-1];
            ar[0][0]=grid[n-1][m-1];
            grid=ar;
        }
        return grid;
    }
};