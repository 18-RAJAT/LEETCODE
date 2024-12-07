class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l=1,r=1e9,mid;
            while(l<r)
            {
                int ans=0;
                mid=l+(r-l)/2;
                for(auto& it:nums)
                {
                    ans+=(it-1)/mid;
                }
                (ans>maxOperations)?l=mid+1:r=mid;
            }
        return l;
    }
};