class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        auto cmp=[](pair<int,int>a,pair<int,int>b)
        {
            return a.first<b.first;
        };
        int n=profits.size();
        vector<pair<int,int>>projects;
        for(int i=0;i<n;++i)
        {
            projects.emplace_back(capital[i],profits[i]);
        }
        sort(projects.begin(),projects.end(),cmp);
        priority_queue<int>maxProfit;
        int i=0;
        while(k--)
        {
            while(i<n and w>=projects[i].first)
            {
                maxProfit.push(projects[i].second);
                i++;
            }
            if(not maxProfit.empty())
            {
                w+=maxProfit.top();
                maxProfit.pop();
            }
        }
        return w;
    }
};