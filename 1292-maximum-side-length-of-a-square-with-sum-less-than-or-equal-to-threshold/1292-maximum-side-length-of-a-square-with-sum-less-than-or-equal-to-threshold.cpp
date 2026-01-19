class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>>prefix(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]- prefix[i-1][j-1]+mat[i-1][j-1];
            }
        }
        int ans=0,res=0;
        for(int i=0;i<=n;++i)
        {
            for(int j=0;j<=m;++j)
            {
                while(i+res<=n && j+res<=m && prefix[i+res][j+res]-prefix[i+res][j]-prefix[i][j+res]+prefix[i][j]<=threshold)
                {
                    ans=res,res++;
                }
            }
        }
        return ans;
    }
};