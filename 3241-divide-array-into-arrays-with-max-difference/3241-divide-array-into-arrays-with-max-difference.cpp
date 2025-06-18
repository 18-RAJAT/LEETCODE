class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i+=3)
        {
            if(i+2>=n || nums[i+2]-nums[i]>k)
            {
                return {};
            }
            else
            {
                vector<int>temp;
                temp.push_back(nums[i]);
                temp.push_back(nums[i+1]);
                temp.push_back(nums[i+2]);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};