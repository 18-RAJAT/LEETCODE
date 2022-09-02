class Solution {
public:
    vector<pair<int,int>>v;
    bool dfs(vector<vector<int>>&grid,int row,int col,int& src,vector<pair<int,int>>&idx,vector<vector<bool>>&visited)
    {
        if(row<0 or col<0 or row>=grid.size() or col>=grid[0].size() or grid[row][col]!=src)
            {return false;}
        
        if(visited[row][col]){return true;}
        visited[row][col]=true;
        bool a,b,c,d;
        a=dfs(grid,row+1,col,src,idx,visited);
        b=dfs(grid,row-1,col,src,idx,visited);
        c=dfs(grid,row,col+1,src,idx,visited);
        d=dfs(grid,row,col-1,src,idx,visited);
        
        if(!(a and b and c and d))v.push_back(make_pair(row,col));
        return true;
    }
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int src=grid[row][col];
        vector<pair<int,int>>idx;
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),0)); // checking for visited nodes
        if(src!=color)dfs(grid,row,col,src,idx,visited);
        for(int i=0;i<v.size();i++){
            grid[v[i].first][v[i].second]=color;
        }
        return grid;
    }
};