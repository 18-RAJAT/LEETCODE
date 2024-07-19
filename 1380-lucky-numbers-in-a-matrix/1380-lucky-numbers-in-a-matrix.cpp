class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<int>row(n,INT_MAX);// minimum values in each column
        vector<int>col(m,INT_MIN);// maximum values in each column
        vector<int>ans;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                row[i]=min(row[i],matrix[i][j]);
            }
        }
        for(int j=0;j<m;++j)
        {
            for(int i=0;i<n;++i)
            {
                col[j]=max(col[j],matrix[i][j]);
            }
        }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(row[i]==matrix[i][j] && col[j]==matrix[i][j])
                {
                    ans.push_back(matrix[i][j]);
                }
            }
        }
        return ans;
    }
};