class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double>ans(105);
        ans[0]=poured;
        for(int row=1;row<=query_row;++row)
        {
            for(int i=row;~i;--i)
            {
                ans[i]=max(0.0,(ans[i]-1)/2);
                ans[i+1]+=ans[i];
            }
        }
        return min(ans[query_glass],1.0);
        
    }
};