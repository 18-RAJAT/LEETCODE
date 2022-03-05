class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int answer = 0;
        
        for(int i=0;i<n;++i)
        {
            if(i != n-i-1)
            {
                answer += mat[i][i] + mat[i][n-i-1];
            }
            
            else
            {
                answer += mat[i][i];
            }
        }
        
        return answer;
        
    }
};