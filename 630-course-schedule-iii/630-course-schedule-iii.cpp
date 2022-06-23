class Solution {
public:
    int scheduleCourse(vector<vector<int>>& c) {
      sort(c.begin(),c.end(),[](vector<int>a,vector<int>b){return a.back()<b.back();});
        priority_queue<int>pq;
        int t=0;
        for(auto course:c)
        {
        pq.push(course[0]);t=t+course[0];
        if(t>course[1]){t=t-pq.top(),pq.pop();}
        }
        return pq.size();
    }
};