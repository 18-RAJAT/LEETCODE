class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        long n=tasks.size();
        long time=0,i=0;
        for(int i=0;i<n;i++)
            tasks[i].push_back(i);
            sort(tasks.begin(),tasks.end());
            vector<int>v;

        while(i<n or !pq.empty())
        {
            if(pq.empty())
                time=max(time,(long)tasks[i][0]);
            while(i<n and time>=tasks[i][0])
            {
                pq.push(make_pair(tasks[i][1],tasks[i][2]));
                i++;
            }
            pair<int,int>st=pq.top();
            pq.pop();
            time+=st.first;
            v.push_back(st.second);
        }
        return v;
    }
};