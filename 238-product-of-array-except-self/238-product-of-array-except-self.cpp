class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
            vector<int>answer(n,1);
            for(int i=1;i<nums.size();++i)
                    answer[i]=answer[i-1]*nums[i-1];
            
            int suffix=1;
            for(int i=n-1;i>=0;--i)
            {
                    answer[i]=answer[i]*suffix;
                    suffix=suffix*nums[i];
            }
            return answer;
    }
};