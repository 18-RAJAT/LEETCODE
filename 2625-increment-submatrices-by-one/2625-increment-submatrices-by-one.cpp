class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>ans(n,vector<int>(n));
        for(auto& it:queries)
        {
            int r1=it[0],r2=it[2],c1=it[1],c2=it[3];
            for(int i=r1;i<=r2;++i)
            {
                for(int j=c1;j<=c2;++j)ans[i][j]++;
            }
        }
        return ans;
    }
};