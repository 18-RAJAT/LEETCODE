class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        
        vector<int>answer;
        
        for(int i=0;i<nums.size();++i)
        {
            for(int j=0;j<nums.size();++j)
            {
                if(abs(i-j) <= k and nums[j] == key)
                {
                    answer.push_back(i);
                    break;
                }
            }
        }
        
        return answer;
        
    }
};