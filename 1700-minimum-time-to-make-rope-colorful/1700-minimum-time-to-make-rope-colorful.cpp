class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
        int prev=-1,ans=0,id=0;
        while(id<n)
        {
            if(~prev && colors[id]==colors[prev])
            {
                int nxt=(neededTime[id]<neededTime[prev]?prev:id);
                ans+=min(neededTime[id],neededTime[prev]);
                prev=nxt;
            }
            else prev=id;
            id++;
        }
        return ans;
    }
};