class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        auto tsk_cmp = [&tasks](const int i, const int j){
            const vector<int> & a = tasks[i];
            const vector<int> & b = tasks[j];
            return a[1] == b[1] ? i > j : a[1] > b[1];
        };

        map<int, vector<int>> timer;
        priority_queue<int, vector<int>, decltype(tsk_cmp)> q(tsk_cmp);
        int n = tasks.size();
        for (int i = 0; i < n; i++)
        {
            timer[tasks[i][0]].push_back(i);
        }

        vector<int> ans;

        auto t = timer.begin();
        int now = 1;
        while (t != timer.end())
        {
            while (t != timer.end() && t->first <= now)
            {
                for (int i : t->second)
                {
                    q.push(i);
                }
                t ++;
            }
            
            if (q.empty())
            {
                now = t->first;
                continue;
            }

            int i = q.top();
            ans.push_back(i);
            now += tasks[i][1];
            q.pop();
        }

        while (!q.empty())
        {
            int i = q.top();
            ans.push_back(i);
            q.pop();
        }

        return ans;
    }
};