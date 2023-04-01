class Solution {
public:

    int ways(vector<string>& pizza, int k) {
        vector<vector<bool>>row;
        vector<vector<bool>>col;
        vector<vector<vector<int>>>dp;
        
        int n=pizza.size();
        int m=pizza[0].size();
        row.resize(n,vector<bool>(m,false));
        col.resize(n,vector<bool>(m,false));
        dp.resize(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                row[i][j]=pizza[i][j]=='A';
                if(j+1<m)
                {
                    row[i][j]=row[i][j] or row[i][j+1];
                }
            }
        }
        auto x=[&](int r,int c)->bool
        {
            return col[r][m-1] or row[n-1][c] or col[r][c];
        };
        function<int(int,int,int)>pruning=[&](int r,int c,int k)->int
        {
            if(r==n)
            {
                return k==0;
            }
            if(k==0 or c==m)
            {
                return 0;
            }
            if(dp[r][c][k]!=-1)
            {
                return dp[r][c][k];
            }
            int ans=0;
            bool appleRow=false;
            for(int i=r;i<n;i++)
            {
                appleRow=appleRow or row[i][c];
                if(appleRow)
                {
                    ans=(ans+pruning(i+1,c,k-1))%1000000007;
                }
            }
            bool appleCol=false;
            for(int i=c;i<m;i++)
            {
                appleCol=appleCol or col[r][i];
                if(appleCol)
                {
                    ans=(ans+pruning(r,i+1,k-1))%1000000007;
                }
            }
            dp[r][c][k]=ans;
            return ans;
        };
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                col[j][i]=pizza[j][i]=='A';
                if(j+1<n)
                {
                    col[j][i]=col[j][i] or col[j+1][i];
                }
            }
        }
        return pruning(0,0,k);
    }
};