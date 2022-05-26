class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums,int result=0) {
                  for(auto i=1,j=1;i<nums.size();++i)
                  {
                         if(nums[i]-nums[i-1] != nums[j]-nums[j-1]){j=i;}
                             result+=i-j;
                    }
            return result;
    }
};