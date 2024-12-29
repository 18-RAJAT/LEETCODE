typedef long long ll;
class Solution {
public:
    int numWays(vector<string>&words,string target) {
        int mod=1e9+7,m=words[0].size(),n=target.size();
        vector<vector<ll>>dict(m,vector<ll>(26,0));
        for(auto& it:words)for(int i=0;i<m;++i)dict[i][it[i]-'a']+=1;
        vector<vector<ll>>f(m,vector<ll>(n,0));
        f[0][0]=dict[0][target[0]-'a'];
        for(int i=1;i<m;++i)
        {
            f[i][0]=(f[i-1][0]+dict[i][target[0]-'a'])%mod;
            for(int j=1;j<n;++j)
            {
                f[i][j]=(f[i-1][j]+((f[i-1][j-1]*dict[i][target[j]-'a'])%mod))%mod;
            }
        }
        return f[m-1][n-1];
    }
};