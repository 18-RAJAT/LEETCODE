class Solution {
public:
    int maxRemoval(vector<int>&nums,vector<vector<int>>&queries) {
        int n=nums.size(),m=queries.size();
        sort(queries.begin(),queries.end());
        priority_queue<int>pq;
        vector<int>ar(n+1,0);
        int id=0,res=0;
        for(int i=0;i<n;++i)
        {
            res+=ar[i];
            while(id<m && queries[id][0]<=i)
            {
                pq.push(queries[id][1]);
                id++;
            }
            while(res<nums[i] && !pq.empty() && pq.top()>=i)
            {
                res++;
                ar[pq.top()+1]--;
                pq.pop();
            }
            if(res<nums[i])return -1;
        }
        return pq.size();
    }
};