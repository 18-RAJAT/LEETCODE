class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) {
        priority_queue<int>pq;
        for(int i=1;i<h.size();++i)
        {
            if(h[i-1]>=h[i]){continue;}
            pq.push(h[i]-h[i-1]);
            b-=h[i]-h[i-1];
            while(b<0 and l and !pq.empty())
            {
                b+=pq.top();pq.pop();l--;
            }
            if(b<0){return i-1;}
        }
        return h.size()-1;
    }
};