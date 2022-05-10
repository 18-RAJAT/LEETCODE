class Solution {
public:
        
   void solve(int previous,int k,int n,int sum,vector<int>temp,vector<vector<int>>&answer)
   {
          if(k==0)
          {
                  if(sum==n)
                  {
                          answer.push_back(temp);
                  }
                  return;
          }
           for(int i=previous;i<=9;++i)
           {
                   temp.push_back(i);
                   solve(i+1,k-1,n,sum+i,temp,answer);
                   temp.pop_back();
           }
   }
        
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>answer;
            vector<int>temp;
            
        solve(1,k,n,0,temp,answer);
            return answer;
    }
};