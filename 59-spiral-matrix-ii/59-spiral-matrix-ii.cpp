class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> v(n,vector<int>(n));
        
        int row_start = 0;
        int row_end = n-1;
        
        int col_start = 0;
        int col_end = n-1;
        
        int temp = 1;
        
        while(row_start <= row_end and col_start <= col_end)
        {
            //1st Iteration
            
            for(int i=col_start;i<=col_end;++i)
            
                v[row_start][i] = temp++;
                row_start++;
                
            
             //2nd Iteration
            
                for(int i=row_start;i<=row_end;++i)
                
                    v[i][col_end] = temp++;
                    
                    col_end--;
            
            //3rd Iteration
            
               for(int i=col_end;i>=col_start;--i)
                   
                   v[row_end][i] = temp++;
                   
                    row_end--;
            
            //4th Iteration
            
              for(int i=row_end;i>=row_start;--i)
                  
                  v[i][col_start] = temp++;
                  
                  col_start++;
            
        }
        
        return v;
        
    }
};