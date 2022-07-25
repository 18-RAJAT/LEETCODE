class Solution {
public:
    void dfs(vector<vector<int>>&rooms,vector<bool>&visited,int idx,int n)
{
    if(visited[idx]==true){return;}//base case
        visited[idx]=true;//if the idx is visited then
        for(auto it:rooms[idx])
        {
            //dfs call 
            dfs(rooms,visited,it,n);
        }
}
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>visited(n,false);//pos + initially false the value
        dfs(rooms,visited,0,n);//dfs call
        // for(int i=0;i<nums.size();++i)
        for(auto it:visited)
        {
        //it the value is of key already taken previously then we will be considered as false
            if(it==false){return false;}
        }
        return true;
    }
};