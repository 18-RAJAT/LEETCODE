class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
        vector<int>dp(n,INT_MAX);
        for(int j=0;j<n;++j)
        {
            int y=0,x=0;
            for(int i=j;i>=0;--i)
            { 
                if((x+=books[i][0])>shelfWidth)break;
                y=max(y,books[i][1]);
                if(!i)dp[j]=min(dp[j],y);
                else dp[j]=min(dp[j],dp[i-1]+y); 
            }
        }
        return dp.back();
    }
};