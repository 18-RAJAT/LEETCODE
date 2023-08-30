class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans=0;
       for(int i=nums.size()-1;i>0;--i)
       {
           if(nums[i]<nums[i-1])
           {
               if(nums[i-1]%nums[i])
               {
                   ans+=nums[i-1]/nums[i];
                   int div=nums[i-1]/nums[i]+1;
                   nums[i-1]/=div;
               }
               else
               {
                  ans+=nums[i-1]/nums[i]-1; 
                  nums[i-1]=nums[i];
               }
           }
       }
       return ans;
    }
};