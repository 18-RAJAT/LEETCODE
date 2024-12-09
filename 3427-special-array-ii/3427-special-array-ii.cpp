class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>ans(n,0);
        for(int i=0;i<n-1;++i)
        {
            if((nums[i]%2)==(nums[i+1]%2))
            {
                ans[i+1]=1;
            }
            ans[i+1]+=ans[i];
        }
        vector<bool>res;
        for(auto& it:queries)
        {
            int f=it[0],s=it[1];
            if(f==s)
            {
                res.push_back(true);
            }
            else
            {
                int count=ans[s]-ans[f];
                res.push_back(count==0);
            }
        }
        return res;
    }
};