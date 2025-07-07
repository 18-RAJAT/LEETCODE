class Solution {
public:
    int maxEvents(vector<vector<int>>& nums) {
        priority_queue<int,vector<int>,greater<int>>pq;
        sort(nums.begin(),nums.end());
        int ans=0,j=0;
        for(int i=1;i<=100000;++i)
        {
            while(!pq.empty() && i>pq.top())pq.pop();
            while(j<nums.size() && nums[j][0]==i)
            {
                pq.push(nums[j][1]);
                j++;
            }
            if(!pq.empty())
            {
                pq.pop();
                ans++;
            }
            if(pq.empty() && j==nums.size())break;
        }
        return ans;
    }
};