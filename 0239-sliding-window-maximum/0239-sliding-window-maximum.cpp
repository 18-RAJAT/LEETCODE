class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int>dq;
        vector<int>ans;
        for(int i=0;i<n;++i)
        {
            //larger ele...
            while(!dq.empty() && nums[dq.back()]<nums[i])dq.pop_back();
            dq.push_back(i);
            //remove ele not in window
            if(dq.front()<=i-k)dq.pop_front();
            //add the max ele
            if(k-1<=i)ans.push_back(nums[dq.front()]);            
        }
        return ans;
    }
};