class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int in[n+1];memset(in,0,sizeof(in));
        int out[n+1];memset(out,0,sizeof(out));
        
        for(auto &it:trust)
        {
            in[it[1]]++;
            out[it[0]]++;
        }
        for(int i=1;i<=n;++i)
        {
            if(out[i]==0 and in[i]==n-1)
            {
                return i;
            }
        }
        return -1;
    }
};