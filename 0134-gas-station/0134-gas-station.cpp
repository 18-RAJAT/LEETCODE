class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int Gas=gas.size();
        int Cost=cost.size();
        int sum_gas=0;
        int sum_cost=0;
        for(int i=0;i<Gas;++i)
        {
            sum_gas+=gas[i];
            sum_cost+=cost[i];
        }
        if(sum_gas<sum_cost)
        {
            return -1;
        }
        int start=0;
        int tank=0;
        for(int i=0;i<Gas;++i)
        {
            tank+=gas[i]-cost[i];
            if(tank<0)
            {
                start=i+1;
                tank=0;
            }
        }
        return start;
    }
};