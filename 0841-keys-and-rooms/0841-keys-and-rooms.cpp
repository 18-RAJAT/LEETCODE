class Solution {
public:
    
    void dfs(int node,vector<int>&used,vector<vector<int>>&rooms,int &ct)
    {
        used[node]=true;
        ct--;
        
        //nbr
        for(auto &it:rooms[node])
        {
            if(used[it]==false)
            {
                dfs(it,used,rooms,ct);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>used(n);
        int ct=n;
        dfs(0,used,rooms,ct);
        
        if(!ct)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};