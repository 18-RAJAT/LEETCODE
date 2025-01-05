class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size(),m=shifts.size();
        vector<int>dp(n+1,0);
        for(int i=0;i<m;++i)
        {
            int start=shifts[i][0],end=shifts[i][1],direction=shifts[i][2];
            if(direction>=1)
            {
                dp[start]++,dp[end+1]--;
            }
            else
            {
                dp[start]--,dp[end+1]++;
            }
        }
        int ans=0;
        for(int i=0;i<n;++i)
        {
            ans+=dp[i];
            int current=s[i]-'a';
            int NewPosition=(current+ans%26+26)%26;
            s[i]='a'+NewPosition;
        }
        return s;
    }
};