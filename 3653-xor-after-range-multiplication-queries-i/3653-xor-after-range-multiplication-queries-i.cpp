class Solution{
public:
    int xorAfterQueries(vector<int>&nums,vector<vector<int>>&queries){
        const long long MOD=1e9+7;
        for(auto& it:queries)
        {
            int l=it[0],r=it[1],k=it[2],v=it[3];
            for(int i=l;i<=r;i+=k)
            {
                nums[i]=(1LL*nums[i]*v)%MOD;
            }
        }
        int ans=0;
        for(auto& it:nums)ans^=it;
        return ans;
    }
};