class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
           
        vector<vector<int>>answer;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();++i)
        {
            int target = -nums[i];
            int front = i+1;
            int back = nums.size() - 1;
            
            while(front < back)
            {
                int sum = nums[front] + nums[back];
                
                // Finding answer which start from number num[i]
                if(sum < target)
                    front++;
                
                else if(sum > target)
                    back--;
                
                else
                {
                    vector<int>triplet = {nums[i],nums[front],nums[back]};
                    
                    answer.push_back(triplet);
                    
                    //Rolling the front pointer next different number forward
                    while(front < back and nums[front] == triplet[1])
                        front++;
                    
                    //Roalling the back pointer next different number backword
                    while(front < back and nums[front] == triplet[2])
                        back--;
                }
            }
            while(i+1 < nums.size() and nums[i+1] == nums[i])
                i++;
        }
        
         return answer;
    }
};