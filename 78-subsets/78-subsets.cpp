class Solution {
public:
    
    int n;
    vector<vector<int>>answer;
    
    vector<int>pair;
    
    vector<vector<int>> subsets(vector<int>& nums) {
    
        n = nums.size();
        backtrack(0,nums);
        return answer;
    }
    
    void backtrack(int index,vector<int>& nums)
    {
        if(index == n)
        {
            answer.push_back(pair);
        }
        
        else
        {
            pair.push_back(nums[index]);
            backtrack(index+1,nums);
            pair.pop_back();
            backtrack(index+1,nums);
        }
    }
    
};