class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int currentTime=0;
        double total=0;
        
        for(auto &ct:customers)
        {
            currentTime=max(currentTime,ct[0])+ct[1];
            total+=currentTime-ct[0];
        }
        double ans=total/customers.size();
        return ans;
    }
};