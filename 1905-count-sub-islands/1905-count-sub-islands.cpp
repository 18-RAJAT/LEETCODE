class Solution {
public:
        int answer=0;
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
            for(int i=0;i<grid2.size();++i)
                    for(int j=0;j<grid2[0].size();++j)
                            if(grid2[i][j] and dfs(grid1,grid2,i,j)){answer++;}
                                 return answer;
    }
        
        bool dfs(vector<vector<int>>& grid1,vector<vector<int>>& grid2,int i,int j)
        {
                if(i==-1 or j==-1 or i==grid2.size() or j==grid2[0].size() or grid2[i][j]==0)
                {return true;}
                
                grid2[i][j]=0;
                bool result=grid1[i][j];
                
                result=dfs(grid1,grid2,i-1,j) and result;
                result=dfs(grid1,grid2,i+1,j) and result;
                result=dfs(grid1,grid2,i,j-1) and result;
                result=dfs(grid1,grid2,i,j+1) and result;
                
                return result; 
        }
};
