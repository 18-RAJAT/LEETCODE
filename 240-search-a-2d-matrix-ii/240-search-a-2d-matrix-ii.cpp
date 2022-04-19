class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        
        int m = 0;
        int n = matrix[0].size()-1;
        
        while(m<matrix.size() and n >=0)
        {
            if(matrix[m][n] == target)
            {
               return true;
            }
            
            if(matrix[m][n] > target)
            {
                n = n - 1;
            }
            
            else
            {
                m = m + 1;
            }
        }
        return false;
    }
};