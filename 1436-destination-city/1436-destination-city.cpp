class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int n=paths.size();
        map<string,vector<string>>in_degree;
        for(auto& it:paths)
        {
            in_degree[it[0]].push_back(it[1]);
        }
        for(auto& it:paths)
        {
            if(in_degree[it[0]].size()==0)
            {
                return it[0];
            }
            if(in_degree[it[1]].size()==0)
            {
                return it[1];
            }
        }
        return "";
    }
};