class Solution{
    int getDist(int a,int b){
        if(a==26)return 0;
        return abs(a/6-b/6)+abs(a%6-b%6);
    }

public:
    int minimumDistance(string word){
        vector<int>dp(27,30005);
        dp[26]=0;
        for(int i=0;i<word.size()-1;++i)
        {
            int curr=word[i]-'A',nxt=word[i+1]-'A';
            vector<int>ndp(27,30005);
            for(int j=0;j<=26;++j)
            {
                if(dp[j]!=30005)
                {
                    ndp[j]=min(ndp[j],dp[j]+getDist(curr,nxt));
                    ndp[curr]=min(ndp[curr],dp[j]+getDist(j,nxt));
                }
            }
            dp=ndp;
        }
        int ans=30005;
        for(auto& it:dp)ans=min(ans,it);
        return ans==30005?0:ans;
    }
};