class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int>sumX(m,0),sumY(m,0);
        int ans=0;
        for(int i=0;i<n;++i)
        {
            int x=0,y=0;
            for(int j=0;j<m;++j)
            {
                if(grid[i][j]=='X')x++;
                else if(grid[i][j]=='Y')y++;
                sumX[j]+=x,sumY[j]+=y;
                if(sumX[j]>=1 && sumX[j]==sumY[j])ans++;
            }
        }
        return ans;
    }
};