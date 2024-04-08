


class Solution {
public:
    int dp[1005][1005];
    string s;
    int lps(int i,int j)
    {
        if(i>j)return 0;
        if(i==j)return 1;
        int &ret=dp[i][j];
        if(~ret)return ret;
        if(s[i]==s[j])return ret=2+lps(i+1,j-1);
        return ret=max(lps(i+1,j),lps(i,j-1));
    }
    int longestPalindromeSubseq(string s) {
        this->s=s;
        fill(&dp[0][0],&dp[0][0]+1005*1005,-1);
        return lps(0,s.size()-1);
    }
};