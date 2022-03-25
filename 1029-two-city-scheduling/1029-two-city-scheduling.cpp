class Solution {
    
    static bool comparator(vector<int>& a,vector<int>& b)
    {
        return a[1]-a[0] > b[1]-b[0];
    }
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        int n = costs.size();
        
        sort(costs.begin(),costs.end(),comparator);
        int answer=0;
        
        for(int i=0;i<n;++i)
        {
            answer += i>=n/2?costs[i][1]:costs[i][0];
        }
        
        return answer;
    }
};