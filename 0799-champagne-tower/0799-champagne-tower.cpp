class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        
        vector<double> result(101);
        result[0] = poured;
        
        for(int row = 1;row <= query_row;++row)
        {
            for(int i= row;i >= 0;--i)
            {
                result[i] = max(0.0,(result[i] - 1) / 2);
                
                result[i+1] += result[i];
            }
        }
        
        return min(result[query_glass],1.0);
        
    }
};