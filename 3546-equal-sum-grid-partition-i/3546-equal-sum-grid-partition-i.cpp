class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        long long int sum1=0,sum2=0;
        if(n==0 || grid[0].size()==0)return false;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                sum1+=grid[i][j];
            }
        }
        if(sum1&1)
        {
            return false;
        }
        sum1/=2;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                sum2+=grid[i][j];
            }
            if(sum1==sum2)
            {
                return true;
            }
        }
        sum2=0;
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                sum2+=grid[j][i];
            }
            if(sum1==sum2)
            {
                return true;
            }
        }
        return false;
    }
};