class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        vector<int>ans,temp;
        vector<vector<int>>res;
        for(int i=0;i<r;++i)
        {
            for(int j=0;j<c;j++)
            {
                ans.push_back(grid[i][j]%12345);
            }
        }
        int mul=r*c;
        vector<int>left(mul),right(mul);
        left[0]=1;
        auto leftHalf=[&]()->void
        {
            for(int i=1;i<mul;++i)
            {
                left[i]=(left[i-1]*ans[i-1])%12345;
            }
        };
        leftHalf();

        right[mul-1]=1;
        
        auto rightHalf=[&]()->void
        {
            for(int i=mul-2;~i;--i)
            {
                right[i]=(right[i+1]*ans[i+1])%12345;
            }
        };
        rightHalf();
        
        auto crossProd=[&](int i)->int
        {
            return (left[i]*right[i])%12345;
        };
        for(int i=0;i<mul;++i)
        {
            temp.push_back(crossProd(i));
            if(temp.size()==c)
            {
                res.push_back(temp);
                temp.clear();
            }
        }
        return res;
    }
};