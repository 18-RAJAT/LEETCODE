class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int current=0;
            int totalCost=0;
            int totalFuel=0;
            int start=0;
            for(int i=0;i<gas.size();++i)
            {
                  totalFuel+=gas[i];  
            }
            for(int i=0;i<gas.size();++i)
            {
                    totalCost+=cost[i];
            }
            
            if(totalFuel<totalCost){return -1;}
            
            for(int i=0;i<gas.size();++i)
            {
                    current+=(gas[i]-cost[i]);
                    if(current<0){start=i+1;current=0;}
            }
            return start;
    }
};