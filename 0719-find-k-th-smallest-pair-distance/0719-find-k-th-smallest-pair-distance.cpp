class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int sz=nums.size();
        sort(nums.begin(),nums.end());
        int l=0,r=nums.back()-nums[0];
        while(l<=r)
        {
            int mid=(l+r)/2;
            int count=0;
            int i=0,j=1;
            
            while(i<sz)
            {
                if(j<=i)j=i+1;
                while(j<sz && nums[j]-nums[i]<=mid)j++;
                
                count+=j-i-1;
                i++;
            }
            (count>=k)?r=mid-1:l=mid+1;
        }
        return l;  
    }
};