class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        if(isConnected.empty())
        {
            return 0;
        }
        
        int n = isConnected.size();
        
        vector<int>leads(n,0);
        
        for(int i=0;i<n;++i)
        {
            leads[i] = i;
        }
        
        int groups = n;
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                if(isConnected[i][j])
                {
                    int lead1 = find(i,leads);
                    int lead2 = find(j,leads);
                    
                    if(lead1 != lead2)
                    {
                        leads[lead1] = lead2;
                        groups--;
                    }
                }
            }
        }
        
        return groups;
        
    }
    
    private:
    int find(int x, vector<int>& parents) {
        return parents[x] == x ? x : find(parents[x], parents);
    }
};