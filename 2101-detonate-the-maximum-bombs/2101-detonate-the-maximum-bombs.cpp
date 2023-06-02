class Solution {
    vector<int>adj[101];
    int detonated[101];
    
   void dfs(int pa)
   {
      detonated[pa]=1;
      
      for(auto ch:adj[pa])
      {
          if(detonated[ch])
          {
              continue;
          }
          dfs(ch);
      }
  }
    
    
public:
    int maximumDetonation(vector<vector<int>>& b) {
        int n=b.size();
        int max_detonated_bombs=0;
        for(int i=0;i<n;i++)
        {
           
            for(int j=0;j<n;j++)
            {
                   long long dis= pow(b[i][0]-b[j][0],2)+pow(b[i][1]-b[j][1],2);
                   if(i!=j and dis<=1LL*pow(b[i][2],2))adj[i].push_back(j);
               }
        }
        
         for(int i=0;i<n;i++)
         {
             memset(detonated,0,sizeof(detonated));
             dfs(i);
             int total_detonated_bombs=0;
             for(int i=0;i<n;i++)
             {
                 if(detonated[i]==1)total_detonated_bombs++;
             }
              max_detonated_bombs=max(max_detonated_bombs,total_detonated_bombs);
         }
        
        return max_detonated_bombs;
        
    }
};