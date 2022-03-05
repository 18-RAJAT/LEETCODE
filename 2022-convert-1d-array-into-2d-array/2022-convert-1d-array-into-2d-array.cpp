class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        
        vector<vector<int>>result;
        
        if(m * n == original.size())
        
            for(auto i : original)
            {
                
                if(result.empty() or result.back().size() == n)
                    
                    //Empty 
                    result.push_back({});
        
                 result.back().push_back(i);
            }
         return result;
        
    }
};