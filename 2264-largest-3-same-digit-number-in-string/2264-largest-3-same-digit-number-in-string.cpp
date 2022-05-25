class Solution {
public:
    string largestGoodInteger(string nums) {
        char ct=0;
            for(int i=2;i<nums.size();++i)
            {
                  if(nums[i]==nums[i-1] and nums[i-1]==nums[i-2]) 
                          ct=max(ct,nums[i]);
            }
            if(ct==0){return "";}
            else
                    return string(3,ct);
    }
};