class Solution {
public:
    bool flag=1;
    void recur(int k,vector<vector<int>>& arr,map<int,int>& mp)
    {
        vector<int>in(k+1,0);
        vector<vector<int>>g(k+1);
        for(int i=0;i<arr.size();++i)
        {
            int u=arr[i][0];
            int v=arr[i][1];
            g[u].push_back(v);
            in[v]++;
        }
        queue<int>q;
        int cycle=0;
        for(int i=1;i<=k;++i)if(in[i]==0)q.push(i);
        int index=1;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            mp[node]=index++;
            cycle++;
            for(auto &it:g[node])
            {
                if(--in[it]==0)q.push(it);
            }
        }
        if(cycle<k)flag=0;
    }
    vector<vector<int>>buildMatrix(int k,vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions)
    {
        map<int,int>row,col;
        recur(k,rowConditions,row);
        recur(k,colConditions,col);
        vector<vector<int>>ans(k,vector<int>(k));
        if(!flag)return {};
        for(int i=1;i<=k;++i)
        {
            ans[row[i]-1][col[i]-1]=i;
        }
        return ans;
    }
};