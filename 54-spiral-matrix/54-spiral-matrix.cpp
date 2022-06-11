class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
            int m=matrix[0].size();
            
            int l=0;
            int r=m-1;
            int b=n-1;
            int t=0;
            int dir=1;
            vector<int>v;
            while(l<=r and t<=b)
            {
                    if(dir==1)
                    {
                            for(int i=l;i<=r;++i)
                                    v.push_back(matrix[t][i]);dir=2;t++;
                    }
                    else if(dir==2)
                    {
                            for(int i=t;i<=b;++i)
                                    v.push_back(matrix[i][r]);dir=3;r--;
                    }
                    else if(dir==3)
                    {
                            for(int i=r;i>=l;--i)
                                    v.push_back(matrix[b][i]);dir=4;b--;
                    }
                    else if(dir==4)
                    {
                            for(int i=b;i>=t;--i)
                                    v.push_back(matrix[i][l]);dir=1;l++;
                    }
            }
            return v;
    }
};