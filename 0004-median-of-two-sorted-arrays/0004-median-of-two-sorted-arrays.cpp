class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<double>v;
        int n=nums1.size();
        int m=nums2.size();
        
        for(int i=0;i<n;++i)
        {
            v.push_back(nums1[i]);
        }
        for(int i=0;i<m;++i)
        {
            v.push_back(nums2[i]);
        }
        sort(begin(v),end(v));
        int sz=v.size();
        return sz%2?v[sz/2]:(v[sz/2-1]+v[sz/2])/2.0;
    }
};