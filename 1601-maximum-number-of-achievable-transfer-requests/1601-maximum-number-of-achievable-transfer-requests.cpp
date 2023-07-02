class Solution {
public:
    int ans=0;
    int sz,n;
    
    int maximumRequests(int n, vector<vector<int>>& req) {
        this->sz=req.size();
        this->n=n;
        int degs[n];
        memset(degs,0,sizeof(degs));
        dfs(req,degs,0,0);
        return ans;
    }
    
    void dfs(vector<vector<int>>& req, int* degs, int idx, int cnt) {
        if(sz==idx) 
        {
            for(int i=0;i<n;++i)
                if(degs[i]!=0)
                    return;
            ans=max<int>(ans,cnt);
            return;
        }
        --degs[req[idx][0]];
        ++degs[req[idx][1]];
        dfs(req,degs,idx+1,cnt+1);
        ++degs[req[idx][0]];
        --degs[req[idx][1]];
        dfs(req,degs,idx+1,cnt);
    }
};