class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        
        int nRows = mat.size();
        int nCols = mat[0].size();
        
        vector<int>rowSum(nRows);
        vector<int>colSum(nCols);
        
        for(int i=0;i<nRows;++i)
        {
            for(int j=0;j<nCols;++j)
            {
                rowSum[i] += mat[i][j];
                colSum[j] += mat[i][j];
            }
        }
        
        int result = 0;
        for(int i=0;i<nRows;++i)
        {
            if(rowSum[i] == 1)
            {
                for(int j=0;j<nCols;++j)
                {
                    if(colSum[j] == 1 and mat[i][j] == 1)
                    {
                        result++;
                        break;
                    }
                }
            }
        }
        return result;
    }
};