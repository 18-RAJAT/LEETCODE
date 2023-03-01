class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {

		// auto comp=[](int a,int b){return a>b;};
		// make_heap(nums.begin(),nums.end(),comp);
		// sort_heap(nums.begin(),nums.end(),comp);
		// return nums;
        
        
        //O(n^2)
		// int n=nums.size();
		// for(int i=0;i<n;++i)
		// {
		// 	for(int j=0;j<n-i-1;++j)
		// 	{
		// 		if(nums[j]>nums[j+1])
		// 		{
		// 			swap(nums[j],nums[j+1]);
		// 		}
		// 	}
		// }
		// return nums;
        
        
        sort(nums.begin(),nums.end());
		return nums;
	}
};