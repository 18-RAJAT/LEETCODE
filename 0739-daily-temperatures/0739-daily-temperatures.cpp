class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>ans(n);
        deque<int>q;
        for(int i=0;i<n;++i)
        {
            while(!q.empty() && temperatures[q.back()]<temperatures[i])
            {
                ans[q.back()]=i-q.back();
                // cout<<i<<endl;
                q.pop_back();
            }
            q.push_back(i);
            // cout<<q.front()<<" ";
        }
        return ans;
    }
};