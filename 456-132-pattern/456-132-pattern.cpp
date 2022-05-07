class Solution {
public:
    bool find132pattern(vector<int>& nums) {
            
            stack<int>stk;
            int temp = INT_MIN;
            for(int i=nums.size() -1 ;i>=0;--i)
            {
                    if(nums[i] < temp){return true;}
                    
                    while (!stk.empty() and stk.top() < nums[i])
                    {
                            temp = stk.top();
                            stk.pop();
                    }
                    stk.push(nums[i]);
            }
        return false;
    }
};