class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=groups.size();
        vector<vector<int>>dp(n,vector<int>(n+1));
        vector<int>w1(n,1),w2(n,1);
        int ans=-1,ert=-1;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                int diff=0;
                int& calc=dp[i][j];
                auto chk=[&]()->void
                {
                    if(words[i].size()==words[j].size())
                    {
                        for(int k=0;k<words[i].size();++k)
                        {
                            diff+=(words[i][k]!=words[j][k]);
                        }
                        calc=diff;
                    }
                };
                chk();
            }
        }
        for(int i=0;i<n;++i)
        {
            w2[i]=i;
            for(int j=0;j<i;++j)
            {
                if(groups[i]!=groups[j] && dp[i][j]==1 && w1[i]<w1[j]+1 && words[i].size()==words[j].size())
                {
                    w1[i]=w1[j]+1;
                    w2[i]=j;
                }
            }
        }
        for(int i=0;i<n;++i)
        {
            if(ans<w1[i])
            {
                ans=w1[i];
                ert=i;
            }
        }
        vector<string>res;
        res.push_back(words[ert]);
        while(w2[ert]!=ert)
        {
            ert=w2[ert];
            res.push_back(words[ert]);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};