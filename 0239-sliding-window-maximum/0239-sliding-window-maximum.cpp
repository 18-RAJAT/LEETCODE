class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        int sz=size(nums);
        for(int i=0;i<sz;++i)
        {
            while(not dq.empty() and dq.front()<=i-k)
            {
                dq.pop_front();
            }
            while(not dq.empty() and nums[dq.back()]<=nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1)
            {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};