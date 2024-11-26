class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>indegree(n);
        int m=edges.size();
        for(int i=0;i<m;++i)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            indegree[v]++;
        }
        vector<int>ans;
        for(int i=0;i<n;++i)
        {
            if(indegree[i]==0)
            {
                ans.push_back(i);
            }
        }
        if(ans.size()==1)
        {
            return ans[0];
        }
        return -1;
        assert(~indegree[0]);
    }
};