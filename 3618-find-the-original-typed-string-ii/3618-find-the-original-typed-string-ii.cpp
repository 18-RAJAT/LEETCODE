class Solution {
public:
    int possibleStringCount(string word, int k) {
        int n=word.size();
        vector<int>ar;
        long long int i=0,ans=1;
        while(i<n)
        {
            long long int cnt=1;
            while((i<n-1) && (word[i]==word[i+1]))
            {
                i++,cnt++;
            }
            ans=(ans*cnt)%1000000007;
            ar.push_back(cnt);
            i++;
        }
        vector<int>dp(k,1),ndp(k);
        i=min<int>(ar.size(),k+2)-1;
        if(i>=0)
        {
            do
            {
                vector<int>res(k+1,0);
                for(int j=0;j<k;++j)
                {
                    res[j+1]=(res[j]+dp[j])%1000000007;
                }
                for(int j=0;j<k;++j)
                {
                    int mn=min(ar[i],j);
                    ndp[j]=(res[j]-res[j-mn]+1000000007)%1000000007;
                }
                dp=ndp;
                i--;
            }while(~i);
        }
        ans=(ans-dp[k-1]+1000000007)%1000000007;
        return ans;
    }
};