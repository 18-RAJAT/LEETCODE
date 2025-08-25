class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>>res(n+m);
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)res[i+j].push_back(mat[i][j]);
        }
        vector<int>ans;
        int cnt=0;
        for(auto& it:res)
        {
            if(cnt&1)
            {
                for(int i=0;i<it.size();++i)ans.push_back(it[i]);
            }
            else
            {
                for(int i=it.size()-1;~i;--i)ans.push_back(it[i]);
            }
            cnt++;
        }
        return ans;
    }
};