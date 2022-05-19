class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int row=matrix.size();
        int column=matrix[0].size();
            set<int>rows;
            set<int>cols;
            
            for(int i=0;i<row;++i)
            {
                    for(int j=0;j<column;++j)
                    {
                            if(matrix[i][j]==0)
                            {
                                    rows.insert(i);
                                    cols.insert(j);
                            }
                    }
            }
            for(int i=0;i<row;++i)
            {
                    for(int j=0;j<column;++j)
                    {
                            if(rows.count(i) or cols.count(j))
                            {
                                    matrix[i][j]=0;
                            }
                    }
            }
    }
};