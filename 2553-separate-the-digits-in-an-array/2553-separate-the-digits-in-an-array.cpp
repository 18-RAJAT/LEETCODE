class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;++i)
        {
            vector<int>temp;
            while(nums[i])
            {
                temp.push_back(nums[i]%10);
                nums[i]/=10;
            }
            int m=temp.size();
            for(int j=m-1;~j;--j) 
            {
                ans.push_back(temp[j]);
            }
            temp.clear();
        }
        return ans;
    }
};