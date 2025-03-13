class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size(),m=queries.size(),l=0,r=m,res=-1;
        auto check=[&](int k)->bool
        {
            vector<long long>arr(n+1,0);
            for(int i=0;i<k;++i)
            {
                int l=queries[i][0],r=queries[i][1],val=queries[i][2];
                arr[l]+=val;
                if(r+1<=n)arr[r+1]-=val;
            }
            long long ans=0;
            for(int i=0;i<n;++i)
            {
                ans+=arr[i];
                if(ans<nums[i])return false;
            }
            return true;
        };
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(check(mid))res=mid,r=mid-1;else l=mid+1;
        }
        return res;
    }
};