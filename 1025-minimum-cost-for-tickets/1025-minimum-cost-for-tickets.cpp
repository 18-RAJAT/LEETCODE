class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        int initial=1;
        vector<int>memo(n,initial);
        function<int(int)>dp=[&](int i)->int
        {
            if(i==n)
            {
                return 0;
            }
            if(memo[i]!=initial)
            {
                return memo[i];
            }
            
            int C1=costs[0]+dp(i+1);//1day ticket
            int take=i;
            
            while(take<n and days[take]<days[i]+7)
            {
                take++;
            }
            
            int C2=costs[1]+dp(take);//7day ticket
            while(take<n and days[take]<days[i]+30)
            {
                take++;
            }
            
            int C3=costs[2]+dp(take);//30day ticket
            
            int minimumCost=min<int>({C1,C2,C3});
            return memo[i]=minimumCost;
        };
        return dp(0);
    }
};