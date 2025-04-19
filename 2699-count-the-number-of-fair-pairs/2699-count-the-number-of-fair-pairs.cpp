class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
		long long n=nums.size();
		sort(nums.begin(),nums.end()); 
		long long ans=0; 
		for(int i=0;i<n;++i)
        { 
			int LB=lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i])-nums.begin(); 
			int UB=upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i])-nums.begin(); 
			ans+=UB-LB;
		} 
		return ans;
    }
};