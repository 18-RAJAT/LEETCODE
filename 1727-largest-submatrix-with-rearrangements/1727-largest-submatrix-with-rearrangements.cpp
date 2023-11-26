class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=1;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(matrix[i][j]==1)
                {
                    matrix[i][j]+=matrix[i-1][j];
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;++i)
        {
            sort(matrix[i].begin(),matrix[i].end());
            // iota(matrix[i].begin(),matrix[i].end(),1);
            for(int j=0;j<m;++j)
            {
                ans=max(ans,matrix[i][j]*(m-j));
            }
        }
        return ans;
    }
};