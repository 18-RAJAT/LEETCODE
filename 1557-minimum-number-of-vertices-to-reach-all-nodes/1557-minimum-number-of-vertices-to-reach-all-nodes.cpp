class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>deg(n,0);
        for(int i=0;i<edges.size();++i)
        {
            deg[edges[i][1]]=1;
        }
        vector<int>ans;
        for(int i=0;i<n;++i)
        {
            if(not deg[i])
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};