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
        int sz=customers.size();
        double ans=total/sz;
        
        return ans;
    }
};