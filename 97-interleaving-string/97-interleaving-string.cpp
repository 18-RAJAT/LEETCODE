class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
      vector<vector<bool>>dp(s1.length()+1, vector<bool>(s2.length()+1, false));
      if(s1.length() + s2.length() != s3.length())
        return false;
      dp[0][0] = true;
      for(int i=1; i<s1.length()+1; i++)
        if(s1[i-1] == s3[i-1])
          dp[i][0] = dp[i-1][0];
      
      for(int i=1; i<s2.length()+1; i++)
        if(s2[i-1] == s3[i-1])
          dp[0][i] = dp[0][i-1];
      
      for(int i=1; i<s1.length()+1; i++){
        for(int j=1; j<s2.length()+1; j++){
          int idx = i+j-1;
          if(s3[idx] == s1[i-1])
            dp[i][j] =  dp[i][j] or dp[i-1][j];
          if(s3[idx] == s2[j-1])
            dp[i][j] =  dp[i][j] or dp[i][j-1];
        }
      }
      return dp[s1.length()][s2.length()];
    }
};