class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n=quality.size();
        vector<pair<double,int>>v;
        for(int i=0;i<n;++i)
        {
            v.push_back({(double)wage[i]/quality[i],quality[i]});
        }
        sort(v.begin(),v.end());
        priority_queue<int>pq;
        int sum=0;
        double ans=1e9;
        for(int i=0;i<n;++i)
        {
            sum+=v[i].second;
            pq.push(v[i].second);
            if(pq.size()>k)
            {
                sum-=pq.top();
                pq.pop();
            }
            if(pq.size()==k)
            {
                ans=min(ans,sum*v[i].first);
            }
        }
        return ans;
    }
};