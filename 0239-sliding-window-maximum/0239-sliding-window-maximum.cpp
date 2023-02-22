class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // monotonic-queue
        
        // deque<int>dq;
        // vector<int>ans;
        // int sz=size(nums);
        // for(int i=0;i<sz;++i)
        // {
        //     while(not dq.empty() and dq.front()<=i-k)
        //     {
        //         dq.pop_front();
        //     }
        //     while(not dq.empty() and nums[dq.back()]<=nums[i])
        //     {
        //         dq.pop_back();
        //     }
        //     dq.push_back(i);
        //     if(i>=k-1)
        //     {
        //         ans.push_back(nums[dq.front()]);
        //     }
        // }
        // return ans;
        
        
        
        //Heap(Priority-queue)
        auto cmp=[&](pair<int,int>a,pair<int,int>b)->int
        {
            return a.first<b.first;
        };
        vector<int>ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)>pq(cmp);
        int sz=nums.size();
        for(int i=0;i<sz;++i)
        {
            if(i<k)
            {
                pq.emplace(nums[i],i);
            }
            else
            {
                ans.push_back(pq.top().first);
                while(not pq.empty() and pq.top().second<=i-k)
                {
                    pq.pop();
                }
                pq.emplace(nums[i],i);
            }
        }
        ans.push_back(pq.top().first);
        return ans;
    }
};