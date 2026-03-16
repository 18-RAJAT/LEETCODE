class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        set<int,greater<int>>s;
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                s.insert(grid[i][j]);
                int mn=min({i,j,m-1-i,n-1-j});
                for(int k=1;k<=mn;++k)
                {
                    int sum=0;
                    for(int l=0;l<k;++l)
                    {
                        sum+=grid[i-k+l][j+l];
                        sum+=grid[i+l][j+k-l];
                        sum+=grid[i+k-l][j-l];
                        sum+=grid[i-l][j-k+l];
                    }
                    s.insert(sum);
                }
            }
        }
        vector<int>ans;
        for(auto& it:s)
        {
            ans.push_back(it);
            if(ans.size()==3)break;
        }
        return ans;
    }
};