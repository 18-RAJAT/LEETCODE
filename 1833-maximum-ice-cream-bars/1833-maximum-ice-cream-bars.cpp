class Solution {
public:
    int maxIceCream(vector<int>& cost, int coin) {
        // sort(cost.begin(),cost.end());
        // int n=cost.size();int ct=0;
        // while(coin>0 and ct<n)
        // {
        //     if(coin>=cost[ct]){coin-=cost[ct];}
        //     else{return ct;}ct++;
        // }
        // return ct;
        sort(cost.begin(),cost.end());int ct=0;
        for(int i=0;i<cost.size();++i)
        {
            if(coin>=cost[i]){coin-=cost[i];ct++;}
        }
        return ct;
    }
};