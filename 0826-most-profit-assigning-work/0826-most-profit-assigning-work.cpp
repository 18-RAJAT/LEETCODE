class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=profit.size();
        vector<pair<int,int>>work;
        for(int i=0;i<n;++i)
        {
            work.push_back(make_pair(difficulty[i],profit[i]));
        }
        sort(work.begin(),work.end());
        sort(worker.begin(),worker.end());
        int j=0,ans=0,max_profit=0;
        for(int i=0;i<worker.size();++i)
        {
            for(;j<n && work[j].first<=worker[i];)
            {
                ans=max(ans,work[j].second),j++;
            }
            max_profit+=ans;
        }
        return max_profit;
    }
};