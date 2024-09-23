class Solution {
public:
    int recur(string &s,int i,vector<string>& dictionary,vector<int> &dp)
    {
        if(i>=s.size())
        {
            return 0;
        }
        if(~dp[i])return dp[i];
        string str="";
        int ans=1e9;
        for(int j=i;j<s.size();++j)
        {
            int cnt=0;
            str.push_back(s[j]);
            if(find(dictionary.begin(),dictionary.end(),str)!=dictionary.end())
            {
                cnt+=recur(s,j+1,dictionary,dp);
            }
            else
            {
                cnt+=str.size()+recur(s,j+1,dictionary,dp);
            }
            ans=min(ans,cnt);
        }
        return dp[i]=ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        return recur(s,0,dictionary,dp);
    }
};