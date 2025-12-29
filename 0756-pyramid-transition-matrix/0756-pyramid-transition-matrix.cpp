class Solution {
public:
    unordered_map<string,int>dp;
    unordered_map<string,set<char>>st;
    int dfs(string s,int i,string t)
    {
        int n=s.size(),m=t.size();
        if(n==1)return 1;
        if(n==m+1)
        {
            if(dp.contains(t))return dp[t];
            return dp[t]=dfs(t,0,"");
        }
        for(auto& it:st[s.substr(i,2)])
        {
            if(dfs(s,i+1,t+it))return 1;
        }
        return 0;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for(auto& it:allowed)
        {
            st[it.substr(0,2)].insert(it.back());
        }
        return dfs(bottom,0,"");
    }
};