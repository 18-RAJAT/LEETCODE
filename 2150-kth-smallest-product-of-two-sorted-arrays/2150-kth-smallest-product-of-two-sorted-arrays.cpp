class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long l=-1e10,r=1e10;
        while(l<r)
        {
            long long mid=l+(r-l+1)/2;
            long long ok=0;
            for(int i=0;i<nums2.size();++i)
            {
                if(nums2[i]>=0)
                {
                    auto it=lower_bound(nums1.begin(),nums1.end(),mid,[&](const auto& a,const auto& b){return 1LL*a*nums2[i]<mid;});
                    ok+=distance(nums1.begin(),it);
                }
                else
                {
                    
                    auto it=lower_bound(nums1.rbegin(),nums1.rend(),mid,[&](const auto& a,const auto& b){return 1LL*a*nums2[i]<mid;});
                    ok+=distance(nums1.rbegin(),it);
                }
            }
            (ok<k)?l=mid:r=mid-1;
        }
        return l;
    }
};