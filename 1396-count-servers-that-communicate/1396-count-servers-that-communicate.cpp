class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    int countServers(vector<vector<int>>&grid) {
        int ans=0;
        vector<int>Row(grid.size());
        vector<int>Col(grid[0].size());
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[i].size();++j)
            {
                if(grid[i][j])
                {
                    Row[i]++,Col[j]++;
                }
            }
        }
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[i].size();++j)
            {
                if(grid[i][j])
                {
                    if(Row[i]>=2)ans++;
                    else if(Col[j]>=2)ans++;
                }
            }
        }
        return ans;
    }
};