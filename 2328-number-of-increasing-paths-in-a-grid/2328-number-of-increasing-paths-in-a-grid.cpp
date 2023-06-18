class Solution {
public:
    using int2=pair<int, int>;
    int countPaths(vector<vector<int>>& grid) {
        const int Mod=1e9+7;
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, -1));
        function<int(int, int)> dfs=[&](int i, int j)
        {
            if (visited[i][j]!=-1) return visited[i][j];
            long result=1;
            vector<int2> adj={{i+1, j},{i, j+1}, {i-1, j}, {i, j-1}};
            for(auto& [a, b]: adj)
            {
            	if (a>=0 && a<n && b>=0 && b<m) 
                    if (grid[a][b]>grid[i][j])
                    {
                        result=(result+dfs(a, b))%Mod;
                    }   
            }
            return visited[i][j]=result;
        };

        long result=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
            	if (visited[i][j]==-1)
                    dfs(i, j);
                result=(result+visited[i][j])%Mod;
            }
        }
        return result;
    }
};