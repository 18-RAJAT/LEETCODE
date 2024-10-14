class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long int ans=0;
        priority_queue<int>pq(nums.begin(),nums.end());
        while(k--)
        {
            int init=pq.top();
            pq.pop();
            ans+=init;
            pq.push((init+2)/3);
        }
        return ans;
    }
};