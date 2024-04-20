class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n=land.size();
        int m=land[0].size();
        vector<vector<int>>ans;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(land[i][j]==1)
                {
                    int x=i,y=j;
                    while(x<n && land[x][j]==1)x++;
                    while(y<m && land[i][y]==1)y++;
                    for(int k=i;k<x;++k)
                    {
                        for(int l=j;l<y;++l)
                        {
                            land[k][l]=0;
                        }
                    }
                    ans.push_back({i,j,x-1,y-1});
                }
            }
        }
        return ans;
    }
};