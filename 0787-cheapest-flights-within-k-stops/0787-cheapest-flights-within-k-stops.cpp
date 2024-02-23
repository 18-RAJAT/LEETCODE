class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int inf = 1e9;
        vector<vector<int>> dp(2, vector<int>(n, inf));
        dp[0][src] = dp[1][src] = 0;
        for (int i = 0; i <= k; i++) {
            for (auto& flight : flights) {
                dp[i % 2][flight[1]] = min(dp[i % 2][flight[1]], dp[(i + 1) % 2][flight[0]] + flight[2]);
            }
        }
        return dp[k % 2][dst] >= inf ? -1 : dp[k % 2][dst];
    }
};