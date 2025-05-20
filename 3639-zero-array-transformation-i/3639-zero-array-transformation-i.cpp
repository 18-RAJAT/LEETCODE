class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size(),m=queries.size();
        vector<int>arr(n+1,0);
        for(int i=0;i<m;++i)
        {
            int l=queries[i][0],r=queries[i][1],val=queries[i][2];
            arr[l]++;
            if(r+1<=n)arr[r+1]--;
        }
        for(int i=1;i<n;++i)arr[i]+=arr[i-1];
        for(int i=0;i<n;++i)if(arr[i]<nums[i])return false;
        return true;
    }
};