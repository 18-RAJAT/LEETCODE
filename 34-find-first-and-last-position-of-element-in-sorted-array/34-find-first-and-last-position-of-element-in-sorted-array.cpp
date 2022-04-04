class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int>answer;

        int start = -1;
        int end = -1;
        
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i] == target)
            {
                if(start == -1)
                {
                    start = i;
                    end = i;
                }
                
                else
                {
                    end = i;
                }
            }
        }
        
        answer.push_back(start);
        answer.push_back(end);
        
        return answer;
        
    }
};