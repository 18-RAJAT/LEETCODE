class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int,int>>>graph(n);
        for(int i=0;i<(int)meetings.size();++i)
        {
            graph[meetings[i][0]].push_back({meetings[i][1],meetings[i][2]});
            graph[meetings[i][1]].push_back({meetings[i][0],meetings[i][2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,firstPerson});
        pq.push({0,0});
        vector<int>res;
        vector<bool>visited(n,false);
        while(!pq.empty())
        {
            pair<int,int>curr=pq.top();
            pq.pop();
            int person=curr.second;
            int time=curr.first;
            if(visited[person])continue;
            visited[person]=true;
            for(pair<int,int>neigh:graph[person])
            {
                if(!visited[neigh.first] && time<=neigh.second)
                {
                    pq.push({neigh.second,neigh.first});
                }
            }
        }
        for(int i=0;i<n;++i)
        {
            if(visited[i])res.push_back(i);
        }
        return res;
    }
};