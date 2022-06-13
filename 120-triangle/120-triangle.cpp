class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int n=t.size();
            for(int i=n-2;i>=0;--i)
            {
                    for(int j=0;j<t[i].size();++j)
                    {
                            int l=t[i+1][j];
                            int r=t[i+1][j+1];
                            
                            t[i][j]=t[i][j]+min(l,r);
                    }
            }
            return t[0][0];
    }
};