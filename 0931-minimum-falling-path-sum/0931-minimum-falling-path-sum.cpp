
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int dp[n][m];
        
        for(int i=0;i<m;++i)
        {
            dp[0][i]=matrix[0][i];
        }
        
        //iterate over the matrix row wise
        for(int i=1;i<n;++i)
        {
            //iterate over the columns
            for(int j=0;j<m;++j)
            {
                if(j==0)
                {
                    //find the minimum of the previous row
                    int mini=min(dp[i-1][j],dp[i-1][j+1]);
                    //add the current element to the minimum of the previous row
                    dp[i][j]=matrix[i][j]+mini;
                }
                
                else if(j==m-1)
                {
                    //same as previous state but we have to find the minimum of the previous row
                    int mini1=min(dp[i-1][j],dp[i-1][j-1]);
                    dp[i][j]=matrix[i][j]+mini1;
                }
                
                else
                {
                    //find the minimum of the previous row and add the current element to it
                    int mini2=min({dp[i-1][j],dp[i-1][j-1],dp[i-1][j+1]});
                    dp[i][j]=matrix[i][j]+mini2;
                }
            }
        }
        
        // for(int i=0;i<n;++i)
        // {
        //     for(int j=0;j<m;++j)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n"; 
        // }

        int result=INT_MAX;
        for(int i=0;i<m;++i)
        {
            result=min(result,dp[n-1][i]);
        }
        return result;
    }
};