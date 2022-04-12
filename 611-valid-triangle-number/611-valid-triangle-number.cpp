class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        
    if(nums.size() < 3)
    {
        return 0;
    }
        
        int answer = 0;
        
        sort(nums.begin(),nums.end());
        
        for(int i=nums.size() - 1; i>0;--i)
        {
            int first = 0;
            int second = i-1;
            
            while(first < second)
            {
                if(nums[first] + nums[second] > nums[i])
                {
                    answer = answer + second - first;
                    
                    --second;
                }
                
                else
                {
                    ++first;
                }
            }
        }
        
        return answer;
        
    }
};
