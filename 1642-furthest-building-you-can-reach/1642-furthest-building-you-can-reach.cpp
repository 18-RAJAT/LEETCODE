class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=1;i<heights.size();++i)
        {
            if(heights[i]>heights[i-1])
            {
                pq.push(heights[i]-heights[i-1]);
                if(pq.size()>ladders)
                {
                    bricks-=pq.top();
                    pq.pop();
                }
                if(bricks<0)
                {
                    return i-1;
                }
            }
        }
        return heights.size()-1;
    }
};