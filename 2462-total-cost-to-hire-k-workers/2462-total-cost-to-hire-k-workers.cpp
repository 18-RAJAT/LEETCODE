class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long cost(0);
        int n(costs.size());
        priority_queue<int,vector<int>,greater<int>>first,second;
        int i(0),j(n-1);
        while(k-->0)
        {
            while(first.size()<candidates and i<=j)
            {
                first.push(costs[i++]);
            }
            while(second.size()<candidates and i<=j)
            {
                second.push(costs[j--]);
            }
            int f=first.size()?first.top():INT_MAX;
            int s=second.size()?second.top():INT_MAX;
            
            if(f<=s)
            {
                cost+=f;
                first.pop();
            }
            else if(f>=s)
            {
                cost+=s;
                second.pop();
            }
        }
        return cost;
    }
};