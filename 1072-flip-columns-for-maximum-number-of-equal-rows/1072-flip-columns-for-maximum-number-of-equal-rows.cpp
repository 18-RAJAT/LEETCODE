class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        map<string,int>mp;
        for(int i=0;i<matrix.size();++i)
        {
            int ok=matrix[i][0];
            string s;
            for(int j=0;j<matrix[i].size();++j)
            {
                s+=ok?('0'+(1-matrix[i][j])):'0'+matrix[i][j];
            }
            mp[s]++;
        }
        int ans=0;
        for(auto it=mp.begin();it!=mp.end();++it)
        {
            ans=max(ans,it->second);
        }
        return ans;
    }
};