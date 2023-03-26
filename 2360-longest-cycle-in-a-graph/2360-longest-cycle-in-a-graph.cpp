class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        int ans=-1;
        vector<int>idx(n);
        for(int i=0,k=1;i<n;++i)
        {
            int ert=i;
            int jo=k;
            while(ert!=-1 and not idx[ert])
            {
                idx[ert]=k++;
                ert=edges[ert];
            }
            if(ert!=-1 and jo<=idx[ert])
            {
                ans=max(ans,k-idx[ert]);
            }
        }
        return ans;
    }
};