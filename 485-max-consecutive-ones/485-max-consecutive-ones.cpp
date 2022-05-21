class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
            int count=0;
            int answer=0;
            for(int i=0;i<nums.size();++i)
            {
                    if(nums[i]==1){count+=1;}
                    else 
                    {
                        if(count>answer)
                         answer=count;
                    count=0;
               }
            }
            if(count>answer){answer=count;}
            return answer;
    }
};