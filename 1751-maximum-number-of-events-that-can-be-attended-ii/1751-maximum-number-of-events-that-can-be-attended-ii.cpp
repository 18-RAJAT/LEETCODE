class Solution {
private:
    unordered_map<int,unordered_map<int,unordered_map<int,int>>> mp;
    int solve(int i,vector<vector<int>>&arr,int k,int prev){
        if(i == arr.size() or !k) return 0;
        if(mp.count(i) and mp[i].count(k) and mp[i][k].count(prev)) return mp[i][k][prev];

        int op1 = 0, op2 = 0;
        if(prev == -1 or arr[i][0] > arr[prev][1]){
            op1 = arr[i][2] + solve(i+1,arr,k-1,i);
        }

        op2 = solve(i+1,arr,k,prev);

        return mp[i][k][prev] = max(op1,op2);
    }
public:
    int maxValue(vector<vector<int>>& arr, int k) {
        sort(arr.begin(),arr.end());
        return solve(0,arr,k,-1);
    }
};