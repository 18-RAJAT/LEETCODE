class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
        int n=nums.size();
        long long sum=0,ans=1e18;
        for(int i=0;i<n;++i)
        {
            sum+=(long long)nums[i];
            if(sum>=k)ans=min<long long>(ans,i+1);
            while(pq.size() && sum-pq.top().first>=k)
            {
                int tp=pq.top().second;
                ans=min<long long>(ans,i-tp);
                pq.pop();
            }
            pq.push({sum,i});
        }
        return ans==1e18?-1:ans;
    }
};