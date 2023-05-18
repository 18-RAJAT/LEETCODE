class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>ans;
        vector<int>trav(n);
        for(auto it:edges)
        {
            trav[it[true]]++;
        }
        for(int i=0;i!=n;++i)
        {
            if(trav[i]==0)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};