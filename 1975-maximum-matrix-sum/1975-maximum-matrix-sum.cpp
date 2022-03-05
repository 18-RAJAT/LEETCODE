class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
     
        int row=matrix.size();
        int column=matrix[0].size();
        
        int small = INT_MAX,count=0;
        
        long long int sum=0;
        
        for(int i=0;i<row;++i)
        {
            for(int j=0;j<column;++j)
            {
                int value = matrix[i][j];
                
                small = min(small,abs(value));
                
                //Check for small values....!!
                if(value < 0)
                    count++;
                
                //Finding the sum of all values
                sum += abs(value);
            }
        }
        
        if(count % 2 == 0)
        {
            return sum;
        }
        else
        {
            return sum - 2*small;
        }
        
    }
};