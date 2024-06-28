class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans=0,x=1;
        vector<int>deg(n,0);
        for(auto& it:roads)
        {
            deg[it[0]]++;
            deg[it[1]]++;
        }
        sort(deg.begin(),deg.end());
        for(int i=0;i<deg.size();++i)
        {
            long long cur=deg[i];
            long long multi=cur*x;
            x++;
            ans += multi;
        }
        return ans;
    }
};