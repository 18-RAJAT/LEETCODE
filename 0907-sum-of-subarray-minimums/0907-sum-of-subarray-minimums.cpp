class Solution {
  static constexpr int MOD = 1e9 + 7;
public:
    int sumSubarrayMins(vector<int>& arr) {  
      stack<int> s;
      
      int n=arr.size();
      long sum=0;
      vector<int> dp(n);
        
      for (int i=0;i<n;++i) 
      {
        
        while(!s.empty() and arr[s.top()]>=arr[i])
          s.pop();
        
        if(s.size()) 
        {
          int prev=s.top();
          dp[i]=dp[prev]+(i-prev)*arr[i];
          
        } 
        
        else
        {
            dp[i]=(i+1)*arr[i];
        }
        sum=(sum+dp[i])%MOD;
        
        s.push(i);
      }
      
      return (int) sum;
    }
};