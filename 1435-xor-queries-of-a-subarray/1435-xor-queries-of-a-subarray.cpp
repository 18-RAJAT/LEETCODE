class Solution {
public:
    vector<int> xorQueries(vector<int>&arr, vector<vector<int>>&queries) {
        int n=arr.size();
        vector<int>prefixXor(n+1,0);
        for(int i=1;i<=n;++i)
        {
            prefixXor[i]=prefixXor[i-1]^arr[i-1];
        }
        vector<int>ans;
        for(auto&q:queries)
        {
            int left=q[0],right=q[1];
            ans.push_back(prefixXor[right+1]^prefixXor[left]);
        }
        return ans;
    }
};