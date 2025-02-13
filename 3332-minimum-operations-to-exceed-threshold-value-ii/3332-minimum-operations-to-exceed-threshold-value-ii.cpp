class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<long long int,vector<long long int>,greater<long long int>> pq;
        for(auto& it:nums)
        {
            pq.push(it);
        }
        long long int ans=0;
        while(pq.size()>=1)
        {
            long long int tp=pq.top();
            pq.pop();
            if(tp>=k)
            {
                return ans;
            }
            if(pq.size()>=1)
            {
                long long int tp2=pq.top();
                pq.pop();
                pq.push(tp*2+tp2);
            }
            ans++;
        }
        return -1;
    }
};