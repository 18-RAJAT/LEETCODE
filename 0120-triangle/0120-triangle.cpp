class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        for(int i=n-2;~i;--i)
        {
            for(int j=0;j<triangle[i].size();++j)
            {
                int l=triangle[i+1][j],r=triangle[i+1][j+1];
                triangle[i][j]=triangle[i][j]+min(l,r);
            }
        }
        return triangle[0][0];
    }
};