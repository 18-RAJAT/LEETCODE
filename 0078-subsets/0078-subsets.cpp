class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        
        for(int i=0;i<pow(2,n);++i)
        {
            vector<int>temp;
            for(int j=0;j<n;++j)
            {
                /*1<<j is a number with jth bit 1 so when we 'and' them with the subset 
                number we get which numbers are present in the subset and which are not*/
                
                if(i&(1<<j))
                {
                    temp.push_back(nums[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};