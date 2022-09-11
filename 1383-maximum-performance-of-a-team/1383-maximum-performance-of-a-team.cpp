class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        priority_queue<vector<int>>pq;
        for(int i=0;i<n;++i)
            pq.push({efficiency[i],speed[i]});
			
        long long cur=0,res=0,mod=pow(10,9)+7;
        priority_queue<int>topSpeed;
        for(int i=0;i<n;++i)
        {
            auto top = pq.top();
            cur += top[1]; pq.pop();
            topSpeed.push(-top[1]);
			
            if(topSpeed.size()>k)
            {
                cur+=topSpeed.top();
                topSpeed.pop();
            }
            res=max(cur*top[0],res);
        }
        return res%mod;
    }
};