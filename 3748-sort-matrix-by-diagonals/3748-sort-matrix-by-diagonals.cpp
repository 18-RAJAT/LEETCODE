class Solution {
public:
    static int cmp(int a,int b){return a>b;}
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                mp[i-j].push_back(grid[i][j]);
            }
        }
        for(auto& it:mp)
        {
            if(it.first<0)sort(it.second.begin(),it.second.end());
            else sort(it.second.begin(),it.second.end(),greater<int>());
        }
        for(int i=n-1;~i;--i)
        {
            for(int j=m-1;~j;--j)
            {
                grid[i][j]=mp[i-j].back();
                mp[i-j].resize(mp[i-j].size()-1);
            }
        }
        return grid;
    }
};