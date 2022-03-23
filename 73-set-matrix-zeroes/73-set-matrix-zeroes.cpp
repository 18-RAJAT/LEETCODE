class Solution {
public:
    
    void setZeroes(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();
        
        bool firstRow = false; //This operation performed to do we need to set first row zero
        bool firstCol = false; //This operation performed to do we need to set first column zero
        
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(matrix[i][j] == 0)
                {
                //Store rows and cols state in first row and column
                if(i == 0)
                {
                    firstRow = true;
                }
                    
                if(j == 0)
                {
                    firstCol = true;
                }
                
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                    
                }
            }
        }
        
        for(int i=1;i<n;++i)
        {
            for(int j=1;j<m;++j)
            {
                if(matrix[i][0] == 0 or matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(firstRow)
        {
            for(int i=0;i<m;++i)
                
                matrix[0][i] = 0;
        }
        
        if(firstCol)
        {
            for(int i=0;i<n;++i)
                
                matrix[i][0] = 0;
        }
    }
};





