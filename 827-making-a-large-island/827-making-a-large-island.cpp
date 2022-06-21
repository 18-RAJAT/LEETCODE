class Solution {
public:
     int dfs(int i,int j,vector<vector<int>>&grid,int &color,int rows,int cols){
        if(i<0 or j<0 or i>=rows or j>=cols){return 0;}
        if(grid[i][j]==0 or grid[i][j]==color){return 0;}
        
        grid[i][j]=color;
        int ct=1;
        ct=ct+dfs(i+1,j,grid,color,rows,cols);
        ct=ct+dfs(i-1,j,grid,color,rows,cols);
        ct=ct+dfs(i,j+1,grid,color,rows,cols);
        ct=ct+dfs(i,j-1,grid,color,rows,cols);
        return ct;
    }
    int largestIsland(vector<vector<int>>& grid)
    {
        int rows=grid.size();int cols=grid[0].size();
        int color=2;
        unordered_map<int,int>mp;
        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                if(grid[i][j]==1)
                {
                    int ct=dfs(i,j,grid,color,rows,cols);
                        mp[color]=ct;color++;
                }
            }
        }
        int result=0;
        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                if(grid[i][j]==0)
                {
                    set<int>st;
                   
                if(i-1>=0 && grid[i-1][j]!=0)
                {
                    st.insert(grid[i-1][j]);
                }
                if(i+1<rows && grid[i+1][j]!=0) 
                {
                    st.insert(grid[i+1][j]);
                }
                if(j-1>=0 && grid[i][j-1]!=0) 
                {
                    st.insert(grid[i][j-1]);
                }
                if(j+1<cols && grid[i][j+1]!=0) 
                {
                    st.insert(grid[i][j+1]);
                }
                
                int sum = 1;
                for(auto i:st)
                    sum += mp[i];
                
                result = max(result, sum);
                }
            }
        }
        return result==0?(rows*cols):result;
    }
};