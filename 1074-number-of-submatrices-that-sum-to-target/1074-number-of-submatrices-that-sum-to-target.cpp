class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
        int result = 0;
        int m = size(matrix);
        int n = size(matrix[0]);
        
        //Calculating the prefix sum of each row of matrix...!!
        
        
        for(int row=0;row<m;++row)
            for(int col=1;col<n;++col)
                
                matrix[row][col] += matrix[row][col-1];
        
        //Another For loop  to col start
        for(int colStart=0;colStart<n;++colStart)
        {
            //Again for loop to column end
            for(int colEnd=colStart;colEnd<n;++colEnd)
            {
                
                //here the row start k lie loop
                for(int rowStart=0;rowStart<m;++rowStart)
                {
                    int sum = 0;
                    
                    //here row end k lie loop
                    for(int rowEnd=rowStart;rowEnd<m;++rowEnd)
                    {
                        sum += matrix[rowEnd][colEnd] - (colStart ? matrix[rowEnd][colStart - 1] : 0);
                        
                        if(sum == target)
                        {
                            result++;
                        }
                    }
                }
            }
        }
        
        return result;
        
    }
};