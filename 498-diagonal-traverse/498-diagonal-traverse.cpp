class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
        vector<int>Result;
        map<int,vector<int>>m;
        
        for(int i=0;i<mat.size();++i)
        {
            for(int j=0;j<mat[0].size();++j)
            {
                m[i+j].push_back(mat[i][j]);
            }
        }
        
        for(auto i : m)
        {
            if((i.first)%2 == 0)
            {
                reverse(i.second.begin(),i.second.end());
            }
            
            for(auto r : i.second)
                Result.push_back(r);
        }
        
        return Result;
    }
};