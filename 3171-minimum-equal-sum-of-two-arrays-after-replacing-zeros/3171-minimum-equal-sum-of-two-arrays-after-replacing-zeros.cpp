class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        long long sum1=0,sum2=0;
        for(int i=0;i<n;++i)
        {
            sum1+=nums1[i];
        }
        for(int i=0;i<m;++i)
        {
            sum2+=nums2[i];
        }
        int count1=count(nums1.begin(),nums1.end(),0);
        int count2=count(nums2.begin(),nums2.end(),0);
        if(sum1==sum2 && count1==0 && count2==0)
        {
            return sum1;
        }
        if((count1==0 && sum2+count2>sum1) || (count2==0 && sum1+count1>sum2))
        {
            return -1;
        }
        return max(sum1+count1,sum2+count2);
    }
};