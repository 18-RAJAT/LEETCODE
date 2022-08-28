class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
    for(int k=0;k<mat.size();k++)
    {
        for(int i=1;i<mat.size();i++)
        {
            for(int j=1;j<mat[0].size();j++)
            {
                if(mat[i][j]<mat[i-1][j-1])
                    swap(mat[i][j],mat[i-1][j-1]);
            }
        }
    }
        return mat;
    }
};