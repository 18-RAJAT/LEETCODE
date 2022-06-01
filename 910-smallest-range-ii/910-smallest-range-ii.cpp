// bool compare(vector<int>&A,vector<int>&B)
// {
//        return A[1]<B[1];
// }

class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {

            int n=nums.size();
            if(n==1){return 0;}
            sort(nums.begin(),nums.end());
            
            int maxDifference=nums[nums.size()-1]-nums[0];
            int maxElement;int minElement;
            
            for(int i=1;i<nums.size();++i)
            {
                    maxElement=max(nums[nums.size()-1]-k,nums[i-1]+k);
                    minElement=min(nums[0]+k,nums[i]-k);
                    
                    maxDifference=min(maxDifference,maxElement-minElement);
            }
            return maxDifference;
    }
};
