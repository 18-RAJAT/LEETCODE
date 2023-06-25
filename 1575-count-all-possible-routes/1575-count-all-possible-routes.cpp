class Solution {
public:
    int dp[100][201];
    int f(int prev, vector<int> &locations, int Cfuel, int finish){

        if(dp[prev][Cfuel]!=-1){
            return dp[prev][Cfuel];
        }


        int ans = 0;
        if(prev==finish){
            ans++;
        }
        for(int i=0; i<locations.size(); i++){
            if(i!=prev && abs(locations[prev]-locations[i]) <= Cfuel){
                ans = (ans + f(i,locations,Cfuel-(abs(locations[prev]-locations[i])), finish))%(int)(1e9+7);
            }
        }
        return dp[prev][Cfuel] = ans;
    }


    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        
        memset(dp,-1,sizeof(dp));
        return f(start,locations,fuel, finish);
    }
};