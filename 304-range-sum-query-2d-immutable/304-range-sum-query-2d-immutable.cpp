class NumMatrix {
public:
    int row=0;
    int col=0;
    vector<vector<int>> dp;
        
    NumMatrix(vector<vector<int>>& matrix) {
        row=matrix.size();
        col=matrix[0].size();
        
        dp.resize(row+1);
        for(auto &v : dp)
        {
            v.resize(col+1);
        }

        for(int i=0;i<=row;i++){
            dp[i][0]=0;
        }
        
        for(int j=1;j<=col;j++){
            dp[0][j]=0;
        }
        
        for(int i=1;i<=row;i++){
            for(int j=1;j<=col;j++){
                dp[i][j]=matrix[i-1][j-1]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2+1][col2+1]-dp[row2+1][col1]-dp[row1][col2+1]+dp[row1][col1];
    }
};
/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
