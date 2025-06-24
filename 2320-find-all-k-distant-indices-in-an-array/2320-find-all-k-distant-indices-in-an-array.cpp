class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n=nums.size(),res=0;
        vector<int>ans;
        for(int i=0;i<n;++i)
        {
            if(nums[i]==key)
            {
                int mx=max(res,i-k);
                res=min(n,i+k+1);
                for(int j=mx;j<res;++j)ans.push_back(j);
            }
        }
        return ans;
    }
};