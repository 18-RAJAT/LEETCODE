class Solution {
public:
    
    vector<vector<int>> generateMatrix(int n) {
        
     vector<vector<int>> v(n,vector<int>(n));
        
        int rowStart = 0;
        int rowEnd = n-1;
        
        int colStart = 0;
        int colEnd = n-1;
        
        int temp = 1;
        
        while(rowStart <= rowEnd and colStart <= colEnd)
        {
            //1st Iteration
            for(int i=colStart;i<=colEnd;++i)
    
                v[rowStart][i] = temp++;
                rowStart++;
            
            //2nd Iteration
            for(int i=rowStart;i<=rowEnd;++i)
                
                v[i][colEnd] = temp++;
                colEnd--;
            
            //3rd Iteration
            for(int i=colEnd;i>=colStart;--i)
            
                v[rowEnd][i] = temp++;
                rowEnd--;
            
            //4th Iteration
            for(int i=rowEnd;i>=rowStart;--i)
                
                v[i][colStart] = temp++;
                colStart++;
        }
        
        return v;
        
    }
};