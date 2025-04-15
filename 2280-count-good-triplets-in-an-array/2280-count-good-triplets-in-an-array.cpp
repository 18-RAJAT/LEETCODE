#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size(),m=nums1.size();
        unordered_map<int,int>mp;
        for(int i=0;i<nums1.size();++i)mp[nums1[i]]=i;
        ordered_set st;
        long long ans=0;
        for(int i=0;i<n;++i)
        {
            int idx=mp[nums2[i]];
            int left=st.order_of_key(idx),right=(n-1-idx)-(st.size()-left);
            ans+=(long long)left*right;
            st.insert(idx);
        }
        return ans;
    }
};